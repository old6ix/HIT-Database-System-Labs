#include "sqltable.h"
#include <QString>
#include <QGridLayout>
#include <QTableWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

SqlTable::SqlTable(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    m_table = new QTableWidget(this);
    m_table->setColumnCount(7);
    m_table->setHorizontalHeaderLabels(QStringList{"Sid", "Sname", "Sage", "Ssex", "Sclass", "Sdept", "Saddr"});

    layout->addWidget(m_table);

    setLayout(layout);

    // 应该从配置文件中读取的，奈何实在太懒
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("DynamicSql.sqlite");
    m_db.open();
}

SqlTable::~SqlTable()
{
    m_db.close();
}

void SqlTable::executeSql(const QString &sql)
{
    /* 查询数据库 */
    QSqlQuery result = QSqlQuery(m_db);
    result.prepare(sql);
    result.exec();

    /* 清空表格 */
    for (int i = m_table->rowCount() - 1; i >= 0; --i) {
        m_table->removeRow(i);
    }

    /* 将结果插入表格 */
    for (int i = 0; result.next(); i++)
    {
        m_table->insertRow(i);
        for (int j = 0; j < 7; j++) { // 共7列
            m_table->setItem(i, j, new QTableWidgetItem(result.value(j).toString()));
        }
    }
}
