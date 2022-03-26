#include "ui_widget/sqlrangefield.h"
#include <QString>
#include <QSpinBox>
#include <QLabel>

SqlRangeField::SqlRangeField(QWidget *parent) : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);

    m_checkbox = new QCheckBox(this);

    auto l1 = new QLabel(this);
    l1->setText("从");
    m_minInput = new QSpinBox(this);

    auto l2 = new QLabel(this);
    l2->setText("到");
    m_maxInput = new QSpinBox(this);

    m_layout->addWidget(m_checkbox);
    m_layout->addWidget(l1);
    m_layout->addWidget(m_minInput);
    m_layout->addWidget(l2);
    m_layout->addWidget(m_maxInput);

    setLayout(m_layout);
}

void SqlRangeField::setFieldName(const QString &name)
{
    m_checkbox->setText(name);
}

bool SqlRangeField::isChecked() const
{
    return m_checkbox->isChecked();
}

int SqlRangeField::getMinInput() const
{
    return m_minInput->text().toInt();
}

int SqlRangeField::getMaxInput() const
{
    return m_maxInput->text().toInt();
}
