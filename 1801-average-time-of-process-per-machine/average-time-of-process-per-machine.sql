# Write your MySQL query statement below


SELECT a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time
FROM Activity as a1 JOIN Activity as a2 on 
a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id
where a1.activity_type = 'start' AND a2.activity_type = 'end'
Group by a1.machine_id;
