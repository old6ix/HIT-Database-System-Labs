#ifndef SQLTABLE_H
#define SQLTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QtSql/QSqlDatabase>

class SqlTable : public QWidget
{
    Q_OBJECT
public:
    explicit SqlTable(QWidget *parent = nullptr);
    ~SqlTable();

public slots:
    void executeSql(const QString &sql);

private:
    QTableWidget *m_table;
    QSqlDatabase m_db;
};

#endif // SQLTABLE_H
