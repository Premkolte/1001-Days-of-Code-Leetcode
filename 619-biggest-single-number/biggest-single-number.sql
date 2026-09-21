# Write your MySQL query statement below
select max(num) as num
from (
    select num
    from MyNumbers
    GROUP BY num 
    HAVING COUNT(num) = 1
)
as num