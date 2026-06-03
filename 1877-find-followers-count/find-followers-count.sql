# Write your MySQL query statement below
-- select user_id, count(follower_id) as followers_count
-- from followers
-- group by user_id
-- order by  user_id

#with clause
-- with newTable as (
--     select user_id, 
--     count(follower_id) as followers_count
--     from followers
--     group by user_id order by user_id asc
-- )
-- select user_id,followers_count
-- from newTable

# using window function
select distinct user_id, followers_count 
from (
    select user_id, 
    count(follower_id) over(partition by user_id) as followers_count
    from followers
) as subquery