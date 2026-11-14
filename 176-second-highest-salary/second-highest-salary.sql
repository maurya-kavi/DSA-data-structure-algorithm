# Write your MySQL query statement below
-- using subqueries method
select max(e.salary) as SecondHighestSalary from employee as e
where salary <
(select max(e.salary) from employee as e)
