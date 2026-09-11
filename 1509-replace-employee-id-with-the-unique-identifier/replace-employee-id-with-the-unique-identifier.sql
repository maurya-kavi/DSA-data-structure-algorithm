-- select * from employees as e 
-- left join employeeuni as eu 
-- on e.id=eu.id;

-- ab jo jo specifically chahiye wo nikal lo

select eu.unique_id , e.name from employees as e 
left join employeeuni as eu 
on e.id=eu.id;