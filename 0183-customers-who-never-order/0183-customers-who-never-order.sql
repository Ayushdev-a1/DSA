# Write your MySQL query statement below
select name AS Customers
from Customers 
left join Orders on Customers.id = Orders.customerId
where Orders.id is null 