# Write your MySQL query statement below
SELECT name,unique_id FROM Employees as em LEFT JOIN EmployeeUNI as e on em.id = e.id;