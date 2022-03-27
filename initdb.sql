-- Create Table
CREATE TABLE Student (
    Sid char(10) primary key ,
    Sname text not null ,
    Sage integer not null ,
    Ssex char(1) not null ,
    Sclass char(8) not null ,
    Sdept char(2) not null ,
    Saddr text not null
);

-- Insert Data
insert into Student values
    ('2002010101', '赵一', 20, '男', '20020101', '03', '黑龙江省哈尔滨市'),
    ('2002010102', '赵二', 18, '女', '20020101', '03', '黑龙江省齐齐哈尔市'),
    ('2002010201', '钱一', 19, '男', '20020102', '04', '黑龙江省哈尔滨市'),
    ('2002010202', '钱二', 20, '男', '20020102', '05', '黑龙江省鸡西市'),
    ('1902010101', '孙一', 21, '女', '20020101', '03', '吉林省长春市'),
    ('1902010102', '孙二', 18, '男', '20010101', '02', '吉林省吉林市')
;
