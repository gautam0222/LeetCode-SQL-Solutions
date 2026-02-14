# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT 
    * 
FROM(
    SELECT
        user_id,
        ROUND(AVG(
            CASE
                WHEN activity_type = 'free_trial' THEN activity_duration
            END
        ), 2) AS trial_avg_duration,
        ROUND(AVG(
            CASE
                WHEN activity_type = 'paid' THEN activity_duration
            end
        ), 2) AS paid_avg_duration 
    FROM UserActivitY
    GROUP BY user_id
) AS a
WHERE paid_avg_duration IS NOT NULL
ORDER BY user_id