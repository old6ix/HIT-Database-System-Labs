# 查询所有学生信息
SELECT *
FROM student
;

# 查询成绩在 80~90（>=80,<=90）分之间的学生的选课信息(学号、课程号和成绩)
SELECT s_id, c_id, score
FROM SC
WHERE score >= 80
  AND score <= 90
;

# 查询并列出所有系名（不重复）
SELECT DISTINCT d_name
FROM student
;

# 查询有多少个同学姓’王’
SELECT COUNT(*)
FROM student
WHERE s_name LIKE '王%'
;

# 查询数据库课程的最高成绩
SELECT MAX(score)
FROM SC
WHERE c_id IN (
    SELECT c_id
    FROM course
    WHERE c_name = '数据库'
)
;

# 将学生的成绩按课号升序，成绩降序排列
SELECT score
FROM SC
ORDER BY c_id, score DESC
;

# 统计每个学生选修的课程数
SELECT student.s_id, COUNT(c_id) as course_cnt
FROM student
         LEFT OUTER JOIN SC on student.s_id = sc.s_id
GROUP BY student.s_id
;
