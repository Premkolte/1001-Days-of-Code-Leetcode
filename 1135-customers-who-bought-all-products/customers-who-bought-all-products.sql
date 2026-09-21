SELECT customer_id
FROM Customer c , Product p
GROUP BY customer_id
HAVING  COUNT(DISTINCT c.product_key) = COUNT(DISTINCT p.product_key)