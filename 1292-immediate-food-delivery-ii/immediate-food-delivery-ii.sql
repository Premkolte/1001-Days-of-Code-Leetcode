select 
    -- round(sum(if(order_date = customer_pref_delivery_date,1,0)) * 100 / count(distinct customer_id),2) as immediate_percentage

    ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage

from Delivery 
where (customer_id, order_date) in (
    select customer_id, min(order_date) as firstorderdate
    from Delivery
    group by customer_id    
)