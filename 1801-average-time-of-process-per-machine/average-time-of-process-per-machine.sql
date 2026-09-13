# Write your MySQL query statement below
-- select a1.machine_id , round(avg(a2.timestamp-a1.timestamp),3) as processing_time
-- from activity a1
-- join activity a2
-- on a1.machine_id=a2.machine_id
-- and a1.process_id = a2.process_id
-- and a1.activity_type='start'
-- and a2.activity_type='end'
-- group by a1.machine_id;


select a.machine_id, round(avg(b.timestamp-a.timestamp),3) as processing_time
from activity a inner join activity b
on a.machine_id=b.machine_id and 
a.process_id = b.process_id and
a.activity_type='start' and b.activity_type='end'
group by a.machine_id
