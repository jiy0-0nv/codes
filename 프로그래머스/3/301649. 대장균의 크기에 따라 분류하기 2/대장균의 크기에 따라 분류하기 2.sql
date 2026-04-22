SELECT A.ID AS "ID",
    (
        CASE
            WHEN A.QUAR = 4 THEN "CRITICAL"
            WHEN A.QUAR = 3 THEN "HIGH"
            WHEN A.QUAR = 2 THEN "MEDIUM"
            WHEN A.QUAR = 1 THEN "LOW"
        END
    ) AS "COLONY_NAME"
FROM (
    SELECT
        ID,
        NTILE(4) OVER (ORDER BY SIZE_OF_COLONY) AS "QUAR"
    FROM ECOLI_DATA
) AS A
ORDER BY A.ID ASC;