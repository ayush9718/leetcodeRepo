-- Write your PostgreSQL query statement below
SELECT Customer.name FROM Customer 
WHERE referee_id IS NULL OR referee_id != 2