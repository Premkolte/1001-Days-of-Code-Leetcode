# Write your MySQL query statement below
select a.activity_date as day,
count(distinct a.user_id) as active_users
from Activity a
where a.activity_date >= '2019-06-28' and a.activity_date <= '2019-07-27'
group by a.activity_date