#include "MainWindow.h"
#include "SleepItemDelegate.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _model(this)
{
    ui.setupUi(this);
    ui.tableView->setModel(&_model);
    ui.tableView->setItemDelegate(new SleepItemDelegate(this));
}
