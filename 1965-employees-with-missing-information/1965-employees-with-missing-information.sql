# Write your MySQL query statement below
select employee_id 
from (
    select employee_id from Employees
    Union all
    select employee_id from Salaries
) t
group by employee_id
having count(*)=1
order by employee_id;