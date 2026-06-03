# Write your MySQL query statement below
# by using window function , modern approach

with RankedSales as(
    select 
    product_id,
    year as first_year,
    quantity,
    price,
    rank() over(partition by product_id order by year asc) as rnk
    from sales
)
select product_id,first_year,quantity,price
from RankedSales
where rnk=1;