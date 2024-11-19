# Write your MySQL query statement below


SELECT s1.project_id , round(avg(experience_years),2) as average_years
FROM Project s1
JOIN Employee e1
ON s1.employee_id = e1.employee_id
group by s1.project_id;
