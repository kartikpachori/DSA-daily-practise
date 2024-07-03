SELECT 
    t1.contest_id,
    ROUND((COUNT(DISTINCT t1.user_id) * 100.0) / (SELECT COUNT( user_id) FROM Users), 2) AS percentage
FROM 
    Register t1
GROUP BY 
    t1.contest_id
ORDER BY 
    percentage DESC,
    t1.contest_id ASC;
