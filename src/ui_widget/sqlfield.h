#ifndef SQLFIELD_H
#define SQLFIELD_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>

enum class SqlFieldType { INT, STR };

class SqlField : public QWidget
{
    Q_OBJECT
public:
    explicit SqlField(QWidget *parent = nullptr, const SqlFieldType &type = SqlFieldType::STR);
    ~SqlField();

    /**
     * @brief 设置字段名
     * @param name 字段名
     */
    void setFieldName(const QString &name);

    /**
     * @brief 查看字段是否被启用
     */
    bool isChecked() const;

    QString getInput() const;

private:
    QHBoxLayout *m_layout;
    QCheckBox *m_checkbox;
    SqlFieldType m_type;
    union {
        QLineEdit *m_strInput;
        QSpinBox *m_intInput;
    };
};

#endif // SQLFIELD_H
