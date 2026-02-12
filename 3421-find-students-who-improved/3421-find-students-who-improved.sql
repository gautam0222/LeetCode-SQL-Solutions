# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT *
FROM
(SELECT 
    t.student_id as student_id,
    t.subject as subject,
    (
        SELECT score
        FROM Scores
        WHERE student_id = t.student_id 
        AND t.min_date = exam_date
        AND t.subject = subject
    ) as first_score,
    (
        SELECT score
        FROM Scores
        WHERE student_id = t.student_id 
        AND t.m_date = exam_date  
        AND t.subject = subject
    ) as latest_score
FROM
(SELECT 
    student_id,
    subject,
    MAX(exam_date) as m_date ,
    MIN(exam_date) as min_date
FROM Scores
GROUP BY student_id,subject
HAVING (COUNT(student_id) > 1) 
AND
(MAX(exam_date) != MIN(exam_date))
) as t
) as tt
WHERE tt.latest_score > tt.first_score
ORDER BY tt.student_id ASC, tt.subject ASC