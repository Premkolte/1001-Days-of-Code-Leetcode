# Write your MySQL query statement below
select project_id, 
ifnull(round(sum(experience_years)/count(*),2), 0.00) as average_years
from Project p
left join Employee e
on p.employee_id = e.employee_id
group by p.project_id