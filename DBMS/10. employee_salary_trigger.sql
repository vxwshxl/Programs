-- ==========================================
-- Q10. Employee Salary Update Validation Trigger
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q10;
USE dbms_lab_q10;

-- Drop trigger if exists
DROP TRIGGER IF EXISTS before_employee_salary_update;

-- Drop table if exists
DROP TABLE IF EXISTS Employee;

-- Create Employee Table
CREATE TABLE Employee (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    e_name VARCHAR(100) NOT NULL,
    salary DECIMAL(10, 2) NOT NULL
);

-- Insert initial sample employees with salaries less than 1000
INSERT INTO Employee (e_name, salary) VALUES
('Ravi Kumar', 750.00),
('Seema Das', 900.00),
('Joy Sen', 500.00);

-- Show initial records
SELECT '--- Initial Employees ---' AS 'Message';
SELECT * FROM Employee;

-- -------------------------------------------------------------------------
-- Create BEFORE UPDATE Trigger to validate salary < 1000
-- -------------------------------------------------------------------------
DELIMITER //

CREATE TRIGGER before_employee_salary_update
BEFORE UPDATE ON Employee
FOR EACH ROW
BEGIN
    -- If the user attempts to set a salary of 1000 or more, raise an error
    IF NEW.salary >= 1000.00 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ERROR: Update blocked. Employee salary must be strictly less than 1000.00.';
    END IF;
END //

DELIMITER ;

-- -------------------------------------------------------------------------
-- Testing Scenarios
-- -------------------------------------------------------------------------

SELECT '--- SCENARIO 1: Attempt to update salary to a valid amount (< 1000) ---' AS 'Test Run';
UPDATE Employee SET salary = 950.00 WHERE e_name = 'Ravi Kumar';

-- Verify the update succeeded
SELECT * FROM Employee;


SELECT '--- SCENARIO 2: Attempt to update salary to an invalid amount (>= 1000) (Should FAIL) ---' AS 'Test Run';
-- This statement is commented out so running the script does not break.
-- Executing this will trigger the custom validation error.
/*
UPDATE Employee SET salary = 1200.00 WHERE e_name = 'Seema Das';
-- Expected Output: ERROR 1644 (45000): ERROR: Update blocked. Employee salary must be strictly less than 1000.00.
*/
