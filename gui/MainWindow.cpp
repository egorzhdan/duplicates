#include "MainWindow.h"
#include "GuiConstants.h"
#include <QLabel>
#include <QHeaderView>
#include <QFileDialog>

MainWindow::MainWindow() : QMainWindow() {
    setWindowFlags(windowFlags() & ~Qt::WindowFullscreenButtonHint);
    setWindowTitle("Duplicates");
    setFixedSize(600, 300);

    infoLabel = new QLabel(InfoLabelText, this);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setTextFormat(Qt::RichText);
    infoLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLabel->setOpenExternalLinks(true);
    infoLabel->setGeometry(QRect(0, size().height() - 25, size().width(), 20));

    openDialogButton = new QPushButton(OpenDialogButtonText, this);
    openDialogButton->setGeometry(QRect(0, 0, size().width() / 3, 30));
    connect(openDialogButton, SIGNAL(released()), this, SLOT(openDialogClicked()));

    pathLabel = new QLabel(this);
    pathLabel->setGeometry(QRect(size().width() / 3, 0, size().width() / 3 * 2, 30));

    runButton = new QPushButton(RunButtonText, this);
    runButton->setGeometry(QRect(0, 30, size().width(), 30));
    runButton->setEnabled(false);
    connect(runButton, SIGNAL(released()), this, SLOT(runClicked()));

    statsView = new QTableWidget(this);
    statsView->setGeometry(QRect(0, 65, size().width(), size().height() - 90));
    statsView->setColumnCount(2);
    statsView->setStyleSheet("QTableWidget { background-color: transparent; }");
    statsView->verticalHeader()->setVisible(false);
    statsView->horizontalHeader()->setVisible(false);
    statsView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    statsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    statsView->setSelectionMode(QAbstractItemView::SingleSelection);
    statsView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::openDialogClicked() {
    auto rootPath = QFileDialog::getExistingDirectory(this);
    pathLabel->setText(rootPath);
    runButton->setEnabled(true);
}

void MainWindow::runClicked() {
    auto rootPath = pathLabel->text();
    auto stats = visitor.traverse(QDir(rootPath));
    auto dupes = stats.getDuplicates();

    statsView->setRowCount(static_cast<int>(dupes.size()));

    for (int i = 0; i < dupes.size(); i++) {
        QString label = "";
        for (const auto& it : dupes[i]) {
            label += it.data();
            label += "\n";
        }
        label = label.remove(label.size() - 1, 1);

        statsView->setItem(i, 0, new QTableWidgetItem(label));
        statsView->setItem(i, 1, new QTableWidgetItem(QString("%1 times").arg(dupes[i].size())));
    }
    statsView->resizeRowsToContents();
}
