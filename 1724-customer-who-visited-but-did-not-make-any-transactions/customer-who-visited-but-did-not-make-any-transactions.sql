select v.customer_id, count(customer_id) as count_no_trans from visits as v left join transactions as t
on v.visit_id = t.visit_id where t.amount is NULL
group by v.customer_id
