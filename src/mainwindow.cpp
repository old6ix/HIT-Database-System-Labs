#include "mainwindow.h"

#include <QGridLayout>
#include <QPushButton>
#include "sqlform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *widget = new SqlForm(this);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

