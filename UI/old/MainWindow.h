#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TimeLineModel.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);

private:
    Ui::MainWindow ui;

    TimeLineModel _model;
};

#endif // MAINWINDOW_H
