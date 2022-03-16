INSERT INTO student
VALUES ('98030101', '张三', '男', 20, '计算机', '980301'),
       ('98030102', '张四', '女', 20, '计算机', '980301'),
       ('98030103', '张五', '男', 19, '计算机', '980301'),
       ('98040201', '王三', '男', 20, '自动控制', '980402'),
       ('98040202', '王四', '男', 21, '自动控制', '980402'),
       ('98040203', '王五', '女', 19, '自动控制', '980402'),
       ('98020101', '李三', '女', 18, '能源', '980201'),
       ('98020102', '李四', '男', 19, '能源', '980201')
;

INSERT INTO course
VALUES ('001', '数据库', 40, 6, 1),
       ('002', '数据结构', 40, 6, 3),
       ('003', '编译原理', 40, 6, 7),
       ('004', 'C 语言', 30, 4.5, 6),
       ('005', '高等数学', 80, 12, 2),
       ('006', '计算机网络', 20, 3, 4)
;

INSERT INTO SC
VALUES ('98030101', '001', 90),
       ('98030101', '002', 86),
       ('98030101', '006', 62),
       ('98030102', '002', 78),
       ('98030102', '004', 66),
       ('98030102', '001', 82),
       ('98030102', '005', 92),
       ('98030102', '006', 50),
       ('98030103', '002', 68),
       ('98030103', '006', 62),
       ('98020101', '001', 80),
       ('98020101', '005', 95),
       ('98020102', '005', 85)
;