#include "DirectoryDialog.h"

DirectoryDialog::DirectoryDialog(QWidget *parent) : QFileDialog(parent) {
    setWindowModality(Qt::WindowModal);
    setFileMode(QFileDialog::DirectoryOnly);
}
