-- ==========================================
-- Q8. Stored Procedures in MySQL
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q8;
USE dbms_lab_q8;

-- Drop tables if they exist
DROP TABLE IF EXISTS Employee;
DROP TABLE IF EXISTS StudentCourses;

-- Drop procedures if they exist
DROP PROCEDURE IF EXISTS AddTwoNumbers;
DROP PROCEDURE IF EXISTS GetMaxSalary;
DROP PROCEDURE IF EXISTS CountSubjectCourses;

-- Create basic Employee Table for Part (ii)
CREATE TABLE Employee (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    e_name VARCHAR(100) NOT NULL,
    salary DECIMAL(10, 2) NOT NULL
);

-- Insert sample Employee salaries
INSERT INTO Employee (e_name, salary) VALUES
('Rohan Das', 45000.00),
('Sneha Sen', 95000.00), -- Max salary
('Vikram Dev', 62000.00),
('Arjun Das', 35000.00);

-- Create StudentCourses Table for Part (iii)
CREATE TABLE StudentCourses (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    student_name VARCHAR(100) NOT NULL,
    subject_name VARCHAR(100) NOT NULL
);

-- Insert sample courses (subjects)
INSERT INTO StudentCourses (student_name, subject_name) VALUES
('Amit', 'DBMS'),
('Priya', 'Mathematics'),
('Rahul', 'DBMS'),
('Neha', 'Computer Networks'),
('Vikram', 'DBMS');

-- Show database state
SELECT '--- Employees ---' AS 'Message'; SELECT * FROM Employee;
SELECT '--- Student Courses ---' AS 'Message'; SELECT * FROM StudentCourses;

-- -------------------------------------------------------------------------
-- i) Write a procedure to add two numbers and return the sum.
-- -------------------------------------------------------------------------
DELIMITER //

CREATE PROCEDURE AddTwoNumbers(
    IN num1 INT,
    IN num2 INT,
    OUT sum_val INT
)
BEGIN
    SET sum_val = num1 + num2;
END //

DELIMITER ;

-- Test Procedure i
SELECT '--- Testing Procedure AddTwoNumbers ---' AS 'Test Run';
SET @sum_result = 0;
CALL AddTwoNumbers(25, 45, @sum_result);
SELECT 25 AS 'Number 1', 45 AS 'Number 2', @sum_result AS 'Sum Result';


-- -------------------------------------------------------------------------
-- ii) Write a procedure to return the maximum salary from a given employee table.
-- -------------------------------------------------------------------------
DELIMITER //

CREATE PROCEDURE GetMaxSalary(
    OUT max_sal DECIMAL(10, 2)
)
BEGIN
    SELECT MAX(salary) INTO max_sal FROM Employee;
END //

DELIMITER ;

-- Test Procedure ii
SELECT '--- Testing Procedure GetMaxSalary ---' AS 'Test Run';
SET @max_salary_val = 0.00;
CALL GetMaxSalary(@max_salary_val);
SELECT @max_salary_val AS 'Maximum Employee Salary';


-- -------------------------------------------------------------------------
-- iii) Create a procedure to count the total number of a particular subject.
--      Provide subject name as IN parameter and count through OUT parameter.
-- -------------------------------------------------------------------------
DELIMITER //

CREATE PROCEDURE CountSubjectCourses(
    IN sub_name VARCHAR(100),
    OUT total_count INT
)
BEGIN
    SELECT COUNT(*) INTO total_count 
    FROM StudentCourses 
    WHERE subject_name = sub_name;
END //

DELIMITER ;

-- Test Procedure iii for subject 'DBMS'
SELECT '--- Testing Procedure CountSubjectCourses for DBMS ---' AS 'Test Run';
SET @dbms_count = 0;
CALL CountSubjectCourses('DBMS', @dbms_count);
SELECT 'DBMS' AS 'Subject', @dbms_count AS 'Total Enrollments/Courses';

-- Test Procedure iii for subject 'Mathematics'
SELECT '--- Testing Procedure CountSubjectCourses for Mathematics ---' AS 'Test Run';
SET @math_count = 0;
CALL CountSubjectCourses('Mathematics', @math_count);
SELECT 'Mathematics' AS 'Subject', @math_count AS 'Total Enrollments/Courses';
