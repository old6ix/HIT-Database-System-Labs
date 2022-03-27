# 课外实验一：动态构造SQL语句

![ScreenShot](https://user-images.githubusercontent.com/23132866/160273624-d3dbf646-d3b4-497e-8a05-e8b68f058129.png)

## 目录

- [实验要求](#实验要求)
- [使用方法](#使用方法)
- [依赖](#依赖)
- [设计思想](#设计思想)
  - [如何构造SQL语句](#如何构造SQL语句)
  - [如何识别模糊匹配](#如何识别模糊匹配)

## 实验要求

编写程序，依据用户输入条件构造SQL语句并执行。

## 使用方法

1. 打开DynamicSqlApp.exe；
2. 勾选过滤字段、输入过滤条件；
3. 点击查询，程序将显示构造出的SQL语句以及查询结果。

## 依赖

- UI框架：[Qt](https://www.qt.io/) 5.12.9
- 数据库：[SQLite](https://sqlite.org)

## 设计思想

### 如何构造SQL语句

本实验的核心是如何根据用户输入的条件构造SQL语句。我借鉴了[SQLAlchemy](https://www.sqlalchemy.org)的设计思想，设计如下的类：

![类图](docs/image/Class%20Diagram.png)

这些类共同产生一条SQL语句。例如，从`stu`表中查询所有`name`以“赵”开头、`age`大于18的行，可用如下的代码生成SQL语句：

```cpp
// using namespace Jiabh
Table("stu").query()
    .filterBy(StrColumn("name").like("赵%"))
    .filterBy(IntColumn("age") > 18)
    .getRawStr();
// SELECT * FROM stu WHERE (name like '赵%') AND (age > 18);
```

也可以采用如下代码：

```cpp
// using namespace Jiabh
Table("stu").query()
    .filterBy(StrColumn("name").like("赵%")
         && IntColumn("age") > 18)
    .getRawStr();
// SELECT * FROM stu WHERE (name like '赵%') AND (age > 18);
```

在一条SQL语句的生成过程中，这些类的状态图如下：

![状态图](docs/image/SQL%20State%20Diagram.png)

WHERE子句可以对每一列施加过滤条件，条件间也可以通过与、或、非运算进行组合。因此Filter类之间应该能通过逻辑运算形成新的过滤条件。与条件相关的类的状态图如下：

![Filter类状态图](docs/image/Filter%20State%20Diagram.png)

如此便可以通过C++代码生成SQL查询语句。

由于实验仅要求简单查询操作，因此只实现了这部分。对于增加、修改和删除操作，按照这种思路应该也能实现。

### 如何识别模糊匹配

根据要求，程序应该能识别用户输入的通配符`%`和`_`，并自动应用LIKE子句进行查询。识别他们比较简单，但需要考虑到转义符的存在。当用户输入`\%`时，程序应能识别到这里不是通配符；当用户输入`\\%`时，又变成了通配符。

此程序选用正则表达式识别通配符，如果找到匹配就采用模糊匹配，反之使用精确匹配。构造的正则表达式如下：

```
[^\\](\\\\)*% | [^\\](\\\\)*_  | ^% | ^_
```

即如果通配符前有奇数个转义符，则该通配符转义；反之不转义。
