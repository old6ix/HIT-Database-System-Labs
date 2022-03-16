CREATE TABLE student
(
    s_id   char(8)     NOT NULL PRIMARY KEY comment '学号',
    s_name varchar(10) NOT NULL comment '姓名',
    sex    char(4) comment '性别',
    age    int comment '年龄',
    d_name varchar(16) comment '院系名称',
    class  char(6) comment '班级号'
);

CREATE TABLE course
(
    c_id     char(3) NOT NULL PRIMARY KEY comment '课程号',
    c_name   varchar(12) comment '课程名',
    hours    int comment '学时',
    credit   float(5) comment '学分',
    semester int comment '授课日期'
);

CREATE TABLE SC
(
    s_id  char(8) NOT NULL comment '学号',
    c_id  char(3) NOT NULL comment '课程号',
    score float(5) comment '成绩',

    PRIMARY KEY (s_id, c_id),
    FOREIGN KEY (s_id) REFERENCES student (s_id),
    FOREIGN KEY (c_id) REFERENCES course (c_id)
);
