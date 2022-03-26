#include "mainwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include "sqlform.h"
#include "sqltable.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto layout = new QVBoxLayout(centralWidget);

    /* 查询表单 */
    auto *formWidget = new SqlForm(centralWidget);
    layout->addWidget(formWidget);

    /* SQL语句显示区域 */
    auto *sqlLabel = new QLabel(centralWidget);
    sqlLabel->setWordWrap(true);
    sqlLabel->setFrameShape(QFrame::Box);
    layout->addWidget(sqlLabel, 2);

    /* 结果显示区域 */
    auto *resTable = new SqlTable(centralWidget);
    layout->addWidget(resTable);

    centralWidget->setLayout(layout);

    connect(formWidget, &SqlForm::sqlConfirmed, sqlLabel, &QLabel::setText);
    connect(formWidget, &SqlForm::sqlConfirmed, resTable, &SqlTable::executeSql);
}

MainWindow::~MainWindow()
{
}
