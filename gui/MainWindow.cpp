#include "MainWindow.h"
#include "DirectoryDialog.h"
#include "GuiConstants.h"
#include <QLabel>

class OpenDialogButton : public QPushButton {
public:
    explicit OpenDialogButton(MainWindow *parent) : QPushButton(parent) {
        setText(OpenDialogButtonText);
    }
};

MainWindow::MainWindow() : QMainWindow() {
    setWindowFlags(windowFlags() & ~Qt::WindowFullscreenButtonHint);
    setWindowTitle("Duplicates");
    setFixedSize(600, 300);

    infoLabel = new QLabel(this);
    infoLabel->setText(InfoLabelText);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setTextFormat(Qt::RichText);
    infoLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLabel->setOpenExternalLinks(true);
    infoLabel->setGeometry(QRect(0, size().height() - 30, size().width(), 20));

    openDialogButton = new OpenDialogButton(this);
    openDialogButton->setGeometry(QRect(0, 0, size().width() / 3, 30));
    connect(openDialogButton, SIGNAL(released()), this, SLOT(openDialogClicked()));

}

void MainWindow::openDialogClicked() {
    auto *dialog = new DirectoryDialog(this);
    dialog->show();

}
