# Write your MySQL query statement below

# with clause

-- with ClassCount as(
--     select class, count(class) as cnt
--     from courses 
--     group by class
-- )

-- select class  from ClassCount
-- where cnt>=5;


# another approach
#by using window function
select distinct class
from (
    select 
    class,
    count(student) over(partition by class) as student_cnt
    from courses
) as subquery
where student_cnt>=5;