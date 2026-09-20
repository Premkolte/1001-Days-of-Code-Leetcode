# Write your MySQL query statement below
-- select 
-- query_name,
-- ifnull(round( sum(q.rating/q.position)/ count(*) ,2) , 0.00) as quality,

-- ifnull(ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2), 0.00)
-- AS poor_query_percentage

-- from Queries q
-- group by q.query_name



SELECT 
  query_name,
  ROUND(AVG(rating / position), 2) AS quality,
  ROUND(SUM(rating < 3) * 100.0 / COUNT(*), 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;

