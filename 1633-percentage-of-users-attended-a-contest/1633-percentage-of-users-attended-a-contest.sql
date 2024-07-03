WITH TotalUsers AS (
    SELECT COUNT(DISTINCT user_id) AS total_users
    FROM Users
),
ContestUsers AS (
    SELECT 
        contest_id, 
        COUNT(DISTINCT user_id) AS distinct_user_count
    FROM 
        Register
    GROUP BY 
        contest_id
)
SELECT 
    cu.contest_id,
    ROUND((cu.distinct_user_count * 100.0) / tu.total_users, 2) AS percentage
FROM 
    ContestUsers cu, TotalUsers tu
ORDER BY 
    percentage DESC,
    cu.contest_id ASC;
