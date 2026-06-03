# Write your MySQL query statement below

select customer_id from (
    select  customer_id,
    count(distinct product_key) as cnt
    from customer
    group by customer_id
) as subquery
where subquery.cnt=(select count(product_key) as totCnt from product)