SELECT ROUND(
           SUM(CASE WHEN (a.player_id, a.event_date) IN (
                        SELECT player_id, DATE_ADD(MIN(event_date), INTERVAL 1 DAY)
                        FROM Activity
                        GROUP BY player_id
                    ) THEN 1 ELSE 0 END)
           / COUNT(DISTINCT a.player_id), 2) AS fraction
FROM Activity a;