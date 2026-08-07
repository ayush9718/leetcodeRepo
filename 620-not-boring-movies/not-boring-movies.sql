# Write your MySQL query statement below
SELECT * FROM Cinema as c
WHERE c.id % 2 = 1 AND c.description != 'boring'
order by c.rating desc;