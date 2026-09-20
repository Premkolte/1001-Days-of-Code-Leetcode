# Write your MySQL query statement below
select p.product_id, 
    ifnull(round(sum(price * units) / sum(units), 2), 0.00)
    as average_price
from Prices p
left join UnitsSold u
on p.product_id = u.product_id 

AND u.purchase_date between p.start_date and p.end_date 
-- took help

group by product_id