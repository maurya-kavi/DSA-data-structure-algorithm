# Write your MySQL query statement below
select max(num) as num
from (
    select num,
    count(num) as cnt
    from mynumbers
    group by num
) as subquery
where cnt=1