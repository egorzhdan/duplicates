#ifndef DUPLICATES_DIRECTORYDIALOG_H
#define DUPLICATES_DIRECTORYDIALOG_H

#include <QFileDialog>

class DirectoryDialog : public QFileDialog {
public:
    explicit DirectoryDialog(QWidget *parent);
};

#endif //DUPLICATES_DIRECTORYDIALOG_H
