# Write your MySQL query statement below
select unique_id, name
from Employees e
left join EmployeeUni u
on e.id = u.id