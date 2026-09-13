-- select max(e.salary) as SecondHighestSalary
-- from employee as e
-- where e.salary<(select max(salary) from employee);


-- select ifnull(
--     (select distinct salary
--     from employee
--     order by salary desc
--     limit 1 offset 1
--     ),
--     null
-- ) as SecondHighestSalary


with RankedSalaries AS(
    select salary, dense_rank() over (order by salary desc) as rnk
    from employee
)
select max(salary) as SecondHighestSalary
from RankedSalaries
where rnk=2;