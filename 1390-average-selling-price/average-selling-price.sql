# Write your MySQL query statement below

SELECT p.product_id ,
CASE WHEN SUM(us.units) IS NULL THEN 0 ELSE ROUND(SUM(p.price*us.units)/SUM(us.units),2) END as average_price
FROM Prices as p LEFT JOIN UnitsSold as us 
ON p.product_id = us.product_id AND us.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id
order by average_price asc; 
