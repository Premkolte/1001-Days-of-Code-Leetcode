# Write your MySQL query statement below
select 
    s.student_id, s.student_name, sub.subject_name, 
    count(e.student_id) as attended_exams
from students s
cross join Subjects sub
left join Examinations e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
group by s.student_id, s.student_name, sub.subject_name
order by s.student_id, sub.subject_name;

