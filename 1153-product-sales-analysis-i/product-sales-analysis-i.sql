-- get column using left join 

-- select * from 
-- sales as s 
-- left join
-- product as p on s.product_id=p.product_id;

-- get only what is asked 
select p.Product_name, s.year, s.price from 
sales as s 
left join
product as p on s.product_id=p.product_id;