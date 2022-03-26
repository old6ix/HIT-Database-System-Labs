#ifndef SQLFORM_H
#define SQLFORM_H

#include <QWidget>
#include "ui_widget/sqlfield.h"
#include "ui_widget/sqlrangefield.h"

class SqlForm : public QWidget
{
    Q_OBJECT
public:
    explicit SqlForm(QWidget *parent = nullptr);

signals:
    void sqlConfirmed(QString sql);

private slots:
    void clickBtnSlot();

private:
    SqlField *m_fSno;
    SqlField *m_fName;
    SqlRangeField *m_fAge;
    SqlField *m_fSex;
    SqlField *m_fClass;
    SqlField *m_fDept;
    SqlField *m_fAddr;
};

#endif // SQLFORM_H
