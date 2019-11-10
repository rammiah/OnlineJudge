# Write your MySQL query statement below
SELECT e0.Name AS Employee FROM Employee AS e0
INNER JOIN Employee AS e1 ON e0.ManagerId = e1.Id 
WHERE e0.Salary > e1.Salary;
