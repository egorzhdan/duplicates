#ifndef DUPLICATES_MAINWINDOW_H
#define DUPLICATES_MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include "core/Visitor.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow();

    ~MainWindow();

public slots:

    void openDialogClicked();

    void runClicked();

    void visitorProcessChanged(int idx, QString fileName);

    void visitorFinished();

    void statsItemClicked(QTableWidgetItem *item);

private:
    Visitor *visitor = nullptr;
    Duplicates dupes;

    QLabel *infoLabel;
    QPushButton *openDialogButton;
    QLabel *pathLabel;
    QPushButton *runButton;
    QTableWidget *statsView;
};

#endif //DUPLICATES_MAINWINDOW_H
