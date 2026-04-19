# Write your MySQL query statement below
select e1.name from 
employee e1 cross join employee e2
on 
-- e1.managerid is null 
-- and 
e1.id=e2.managerid
group by e1.id, e1.name
having count(e2.id) >=5;