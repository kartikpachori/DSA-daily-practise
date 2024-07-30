WITH RankedPrices AS (
    SELECT 
        product_id, 
        new_price,
        ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY change_date DESC) as rnk
    FROM Products
    WHERE change_date <= '2019-08-16'
)
SELECT 
    p.product_id,
    COALESCE(r.new_price, 10) as price
FROM 
    (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN 
    RankedPrices r
ON 
    p.product_id = r.product_id AND r.rnk = 1
ORDER BY 
    p.product_id;
