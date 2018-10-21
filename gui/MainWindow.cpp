#include "MainWindow.h"
#include "DirectoryDialog.h"
#include "GuiConstants.h"
#include <QLabel>

MainWindow::MainWindow() : QMainWindow() {
    setWindowFlags(windowFlags() & ~Qt::WindowFullscreenButtonHint);
    setWindowTitle("Duplicates");
    setFixedSize(600, 300);

    infoLabel = new QLabel(InfoLabelText, this);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setTextFormat(Qt::RichText);
    infoLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLabel->setOpenExternalLinks(true);
    infoLabel->setGeometry(QRect(0, size().height() - 30, size().width(), 20));

    openDialogButton = new QPushButton(OpenDialogButtonText, this);
    openDialogButton->setGeometry(QRect(0, 0, size().width() / 3, 30));
    connect(openDialogButton, SIGNAL(released()), this, SLOT(openDialogClicked()));

    pathLabel = new QLabel(this);
    pathLabel->setGeometry(QRect(size().width() / 3, 0, size().width() / 3 * 2, 30));

    runButton = new QPushButton(RunButtonText, this);
    runButton->setGeometry(QRect(0, 30, size().width(), 30));
    runButton->setEnabled(false);
    connect(runButton, SIGNAL(released()), this, SLOT(runClicked()));
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

}
