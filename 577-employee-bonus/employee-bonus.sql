# Write your MySQL query statement below

SELECT e.name , b.bonus FROM Employee as e 
LEFT JOIN Bonus as b 
ON e.empId = b.empId 
where b.bonus < 1000 OR b.bonus IS NULL
ORDER BY b.bonus asc ; 