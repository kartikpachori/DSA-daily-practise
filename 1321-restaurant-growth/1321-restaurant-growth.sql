WITH DailyTotal AS (
  SELECT 
    visited_on,
    SUM(amount) AS total_amount
  FROM Customer
  GROUP BY visited_on
),
SevenDayWindow AS (
  SELECT 
    visited_on,
    SUM(total_amount) OVER (
      ORDER BY visited_on 
      ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS window_sum,
    ROUND(
      AVG(total_amount) OVER (
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
      ), 2
    ) AS average_amount,
    COUNT(total_amount) OVER (
      ORDER BY visited_on 
      ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS cnt
  FROM DailyTotal
)
SELECT 
  visited_on,
  window_sum AS amount,
  average_amount
FROM SevenDayWindow
WHERE cnt = 7
ORDER BY visited_on;
