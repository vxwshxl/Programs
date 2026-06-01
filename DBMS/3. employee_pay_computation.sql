-- ==========================================
-- Q3. Employee Salary Computations & Aggregations
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q3;
USE dbms_lab_q3;

-- Drop table if exists to allow clean re-runs
DROP TABLE IF EXISTS Employee;

-- Create the Employee Table
CREATE TABLE Employee (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    e_name VARCHAR(100) NOT NULL,
    designation VARCHAR(50) NOT NULL,
    basic_pay DECIMAL(10, 2) NOT NULL
);

-- Insert exactly 5 employees with basic pay tailored to test gross ranges
INSERT INTO Employee (e_name, designation, basic_pay) VALUES
('Ramesh Kumar', 'Developer', 7000.00),   -- Gross = 13,300 (In range 5k-15k)
('Sita Sharma', 'HR Assistant', 4000.00), -- Gross = 7,600 (In range 5k-15k)
('Ganesh Das', 'Office Assistant', 3000.00), -- Gross = 5,700 (In range 5k-15k)
('Karan Johar', 'Intern', 2000.00),      -- Gross = 3,800 (Below 5k)
('Sunita Sen', 'Project Lead', 10000.00);  -- Gross = 19,000 (Above 15k)

-- Show initial records
SELECT '--- Initial Employee Basic Pay ---' AS 'Message';
SELECT * FROM Employee;

-- -------------------------------------------------------------------------
-- i) Find out gross salary and net salary where:
--    DA = 60%, TA = 20%, HRA = 10%, TAX = 15% of Gross
--    GROSS = Basic + DA + TA + HRA
--    NET = GROSS - TAX
-- -------------------------------------------------------------------------
SELECT '--- Salary Statement (Gross & Net Calculations) ---' AS 'Query i';
SELECT 
    emp_id, 
    e_name, 
    designation, 
    basic_pay,
    (basic_pay * 0.60) AS DA,
    (basic_pay * 0.20) AS TA,
    (basic_pay * 0.10) AS HRA,
    (basic_pay * (1 + 0.60 + 0.20 + 0.10)) AS GROSS_SALARY,
    (basic_pay * (1 + 0.60 + 0.20 + 0.10) * 0.15) AS TAX,
    (basic_pay * (1 + 0.60 + 0.20 + 0.10) * (1 - 0.15)) AS NET_SALARY
FROM Employee;

-- -------------------------------------------------------------------------
-- ii) Find the total number of employees.
-- -------------------------------------------------------------------------
SELECT '--- Total Number of Employees ---' AS 'Query ii';
SELECT COUNT(*) AS total_employees 
FROM Employee;

-- -------------------------------------------------------------------------
-- iii) Find the total number of employees having gross salary between 5000 and 15000.
-- Note: Gross is computed as basic_pay * 1.9
-- -------------------------------------------------------------------------
SELECT '--- Total Employees with Gross Salary Between 5000 and 15000 ---' AS 'Query iii';
SELECT COUNT(*) AS count_in_range
FROM Employee
WHERE (basic_pay * 1.9) BETWEEN 5000.00 AND 15000.00;

-- -------------------------------------------------------------------------
-- iv) Find the maximum gross salary.
-- -------------------------------------------------------------------------
SELECT '--- Maximum Gross Salary ---' AS 'Query iv';
SELECT MAX(basic_pay * 1.9) AS max_gross_salary 
FROM Employee;

-- -------------------------------------------------------------------------
-- v) Display the details of the employee who gets the maximum gross salary.
-- -------------------------------------------------------------------------
SELECT '--- Employee Getting Maximum Gross Salary ---' AS 'Query v';
SELECT 
    emp_id, 
    e_name, 
    designation, 
    basic_pay,
    (basic_pay * 1.9) AS gross_salary,
    ((basic_pay * 1.9) * 0.85) AS net_salary
FROM Employee
WHERE basic_pay = (SELECT MAX(basic_pay) FROM Employee);
