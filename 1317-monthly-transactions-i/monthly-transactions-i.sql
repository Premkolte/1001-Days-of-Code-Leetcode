# Write your MySQL query statement below
select 
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country, 
    COUNT(id) AS trans_count,

    -- SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(state = 'approved') AS approved_count,

    SUM(amount) AS trans_total_amount,

    -- SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
    SUM(if(state = 'approved' , amount, 0)) AS approved_total_amount
    

from Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;