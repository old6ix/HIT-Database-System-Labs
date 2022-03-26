#include "ui_widget/sqlfield.h"
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>

SqlField::SqlField(QWidget *parent, const SqlFieldType &type) : QWidget(parent), m_type(type)
{
    m_layout = new QHBoxLayout(this);

    m_checkbox = new QCheckBox(this);
    m_layout->addWidget(m_checkbox);

    switch (type) {
        case SqlFieldType::STR:
            m_strInput = new QLineEdit();
            m_layout->addWidget(m_strInput);
            break;
        case SqlFieldType::INT:
            m_intInput = new QSpinBox();
            m_layout->addWidget(m_intInput);
            break;
        default:
            break;
    }

    setLayout(m_layout);
}

SqlField::~SqlField()
{
    delete m_layout;
    delete m_checkbox;
    delete m_strInput;
}

void SqlField::setFieldName(const QString &name)
{
    m_checkbox->setText(name);
}

bool SqlField::isChecked() const
{
    return m_checkbox->isChecked();
}

QString SqlField::getInput() const
{
    switch (m_type) {
        case SqlFieldType::STR:
            return m_strInput->text();
        case SqlFieldType::INT:
            return m_intInput->text();
        default:
            return "Error!";
    }
}
