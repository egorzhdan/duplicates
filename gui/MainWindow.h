#ifndef DUPLICATES_MAINWINDOW_H
#define DUPLICATES_MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "core/Visitor.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow();

private slots:
    void openDialogClicked();

private:
    Visitor visitor;

    QLabel *infoLabel;
    QPushButton *openDialogButton;
};

#endif //DUPLICATES_MAINWINDOW_H
