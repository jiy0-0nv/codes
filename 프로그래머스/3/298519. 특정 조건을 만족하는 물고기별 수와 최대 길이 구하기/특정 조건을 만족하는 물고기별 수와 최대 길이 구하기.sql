SELECT
    -- 잡은 수
    ID,
    -- 최대 길이
    MAX_LENGTH,
    -- 물고기 종류
    FISH_TYPE
FROM (
    SELECT 
        COUNT(ID) AS 'ID', -- 잡은 수
        MAX(LENGTH) AS 'MAX_LENGTH', -- 최대 길이
        FISH_TYPE AS 'FISH_TYPE', -- 물고기 종류
        AVG(IFNULL(LENGTH, 10)) AS 'AVG_LENGTH'-- 평균 길이
    FROM FISH_INFO
    GROUP BY FISH_TYPE
) AS D
WHERE AVG_LENGTH >= 33
ORDER BY FISH_TYPE;