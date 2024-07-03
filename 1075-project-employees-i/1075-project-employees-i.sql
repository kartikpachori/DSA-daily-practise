SELECT 
    t1.project_id,
    ROUND(AVG(t2.experience_years), 2) AS average_years
FROM 
    Project t1
JOIN 
    Employee t2
ON 
    t1.employee_id = t2.employee_id
GROUP BY 
    t1.project_id;
