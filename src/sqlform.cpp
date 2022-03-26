#include "sqlform.h"

#include <QGridLayout>
#include <QPushButton>
#include "ui_widget/sqlfield.h"
#include "ui_widget/sqlrangefield.h"
#include "jiabh/table.h"
#include "jiabh/query.h"
#include "jiabh/column.hpp"

SqlForm::SqlForm(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    m_fSno = new SqlField(this);
    m_fSno->setFieldName("学号");

    m_fName = new SqlField(this);
    m_fName->setFieldName("姓名");

    m_fAge = new SqlRangeField(this);
    m_fAge->setFieldName("年龄");

    m_fSex = new SqlField(this);
    m_fSex->setFieldName("性别");

    m_fClass = new SqlField(this);
    m_fClass->setFieldName("班级");

    m_fDept = new SqlField(this);
    m_fDept->setFieldName("系别");

    m_fAddr = new SqlField(this);
    m_fAddr->setFieldName("地址");

    auto button = new QPushButton(this);
    button->setText("查询");

    layout->addWidget(m_fSno, 0, 0);
    layout->addWidget(m_fName, 1, 0);
    layout->addWidget(m_fAge, 2, 0);
    layout->addWidget(m_fSex, 3, 0);
    layout->addWidget(m_fClass, 0, 1);
    layout->addWidget(m_fDept, 1, 1);
    layout->addWidget(m_fAddr, 2, 1);
    layout->addWidget(button, 3, 1);

    setLayout(layout);

    connect(button, &QPushButton::clicked, this, &SqlForm::clickBtnSlot);
}

void SqlForm::clickBtnSlot()
{
    Jiabh::Query q = Jiabh::Table("student").query();

#define CHECK_AND_QUERY(valName, colName) \
    if (valName->isChecked()) { \
        QString str = valName->getInput(); \
        if (str.indexOf(QRegExp("[^\\\\]%|[^\\\\]_|^%|^_")) != -1) \
            q.filterBy(Jiabh::StrColumn(#colName).like(str)); \
        else \
            q.filterBy(Jiabh::StrColumn(#colName) == str); \
    }

    CHECK_AND_QUERY(m_fSno, Sid)
    CHECK_AND_QUERY(m_fName, Sname)

    if (m_fAge->isChecked()) {
        auto ageCol = Jiabh::IntColumn("Sage");
        q.filterBy(ageCol >= m_fAge->getMinInput())
                .filterBy(ageCol <= m_fAge->getMaxInput());
    }

    CHECK_AND_QUERY(m_fSex, Ssex)
    CHECK_AND_QUERY(m_fClass, Sclass)
    CHECK_AND_QUERY(m_fDept, Sdept)
    CHECK_AND_QUERY(m_fAddr, Saddr)


    QString sql = q.getRawStr();
    emit sqlConfirmed(sql);
}
