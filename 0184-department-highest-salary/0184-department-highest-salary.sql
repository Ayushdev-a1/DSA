# Write your MySQL query statement below
select D.name as Department , E.name as Employee , E.salary as Salary
from Employee E 
join Department D on D.id = E.departmentId
JOIN (
    SELECT departmentId, MAX(salary) AS maxSalary
    FROM Employee
    GROUP BY departmentId
) m
ON e.departmentId = m.departmentId
AND e.salary = m.maxSalary;