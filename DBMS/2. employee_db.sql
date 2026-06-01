-- ==========================================
-- Q2. Employee Database & Basic Queries
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q2;
USE dbms_lab_q2;

-- Drop table if exists to allow clean re-runs
DROP TABLE IF EXISTS Employee;

-- Create the Employee Table
CREATE TABLE Employee (
    emp_id INT PRIMARY KEY,
    e_name VARCHAR(100) NOT NULL,
    designation VARCHAR(50) NOT NULL,
    salary DECIMAL(10, 2) NOT NULL,
    dept VARCHAR(50) NOT NULL
);

-- Insert realistic sample data representing various departments and salary ranges
INSERT INTO Employee (emp_id, e_name, designation, salary, dept) VALUES
(101, 'Amit Sharma', 'Manager', 75000.00, 'HR'),
(102, 'Priya Patel', 'Developer', 45000.00, 'IT'),
(103, 'Rahul Verma', 'Executive', 25000.00, 'HR'),
(104, 'Sneha Reddy', 'Manager', 80000.00, 'Finance'),
(105, 'Vikram Singh', 'Analyst', 35000.00, 'IT'),
(106, 'Neha Gupta', 'Executive', 18000.00, 'Sales'),
(107, 'Arjun Kumar', 'Manager', 65000.00, 'HR'),
(108, 'Pooja Sen', 'Director', 120000.00, 'Operations');

-- Show the loaded table
SELECT '--- Initial Employee Table ---' AS 'Message';
SELECT * FROM Employee;

-- -------------------------------------------------------------------------
-- i) Display the details of employees working in the HR department.
-- -------------------------------------------------------------------------
SELECT '--- HR Department Employees ---' AS 'Query i';
SELECT * 
FROM Employee 
WHERE dept = 'HR';

-- -------------------------------------------------------------------------
-- ii) Display the names of employees who are getting a salary within the range 20k to 50k.
-- -------------------------------------------------------------------------
SELECT '--- Employees with Salary Between 20k and 50k ---' AS 'Query ii';
SELECT e_name, salary 
FROM Employee 
WHERE salary BETWEEN 20000.00 AND 50000.00;

-- -------------------------------------------------------------------------
-- iii) Display the IDs of employees who is a manager and getting salary more than 60k.
-- -------------------------------------------------------------------------
SELECT '--- Manager with Salary > 60k ---' AS 'Query iii';
SELECT emp_id, e_name, designation, salary 
FROM Employee 
WHERE designation = 'Manager' AND salary > 60000.00;
