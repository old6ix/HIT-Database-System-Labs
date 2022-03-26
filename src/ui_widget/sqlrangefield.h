#ifndef SQLRANGEFIELD_H
#define SQLRANGEFIELD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QSpinBox>

class SqlRangeField : public QWidget
{
    Q_OBJECT
public:
    explicit SqlRangeField(QWidget *parent = nullptr);

    /**
     * @brief 设置字段名
     * @param name 字段名
     */
    void setFieldName(const QString &name);

    /**
     * @brief 查看字段是否被启用
     */
    bool isChecked() const;

    int getMinInput() const;

    int getMaxInput() const;

private:
    QHBoxLayout *m_layout;
    QCheckBox *m_checkbox;
    QSpinBox *m_minInput;
    QSpinBox *m_maxInput;
};

#endif // SQLRANGEFIELD_H
