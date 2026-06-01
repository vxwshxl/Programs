-- ==========================================
-- Q9. Student Triggers (Validation & Logging)
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q9;
USE dbms_lab_q9;

-- Drop triggers if they exist
DROP TRIGGER IF EXISTS before_student_insert;
DROP TRIGGER IF EXISTS before_student_update;
DROP TRIGGER IF EXISTS after_student_insert;

-- Drop tables if they exist
DROP TABLE IF EXISTS student_log;
DROP TABLE IF EXISTS students;

-- 1. Create students Table
CREATE TABLE students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    student_name VARCHAR(100) NOT NULL,
    age INT NOT NULL,
    marks DECIMAL(5, 2) NOT NULL,
    created_at TIMESTAMP NULL DEFAULT NULL -- Will be populated by the BEFORE INSERT trigger
);

-- 2. Create student_log Table
CREATE TABLE student_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    student_name VARCHAR(100),
    action_type VARCHAR(50) DEFAULT 'INSERT',
    logged_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- -------------------------------------------------------------------------
-- iii) Trigger: Sets created_at,
-- ii) Trigger: Blocks age < 18,
-- iv) Trigger: Blocks insertion if marks < 0
-- (All packaged into a unified BEFORE INSERT trigger)
-- -------------------------------------------------------------------------
DELIMITER //

CREATE TRIGGER before_student_insert
BEFORE INSERT ON students
FOR EACH ROW
BEGIN
    -- iii) Automatically set created_at to current timestamp
    SET NEW.created_at = NOW();

    -- ii) Check age constraint: prevent age < 18
    IF NEW.age < 18 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ERROR: Insertion blocked. Student age must be 18 or older.';
    END IF;

    -- iv) Check marks constraint: prevent marks < 0
    IF NEW.marks < 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ERROR: Insertion blocked. Marks cannot be less than 0.';
    END IF;
END //

DELIMITER ;

-- -------------------------------------------------------------------------
-- iv) Trigger: Stops UPDATE if marks < 0
-- -------------------------------------------------------------------------
DELIMITER //

CREATE TRIGGER before_student_update
BEFORE UPDATE ON students
FOR EACH ROW
BEGIN
    -- iv) Check marks constraint on UPDATE: prevent marks < 0
    IF NEW.marks < 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ERROR: Update blocked. Marks cannot be less than 0.';
    END IF;
END //

DELIMITER ;

-- -------------------------------------------------------------------------
-- i) Trigger: Logs successful inserts into student_log
-- -------------------------------------------------------------------------
DELIMITER //

CREATE TRIGGER after_student_insert
AFTER INSERT ON students
FOR EACH ROW
BEGIN
    INSERT INTO student_log (student_id, student_name, action_type)
    VALUES (NEW.student_id, NEW.student_name, 'INSERT');
END //

DELIMITER ;

-- -------------------------------------------------------------------------
-- Verification and Testing Scenarios
-- -------------------------------------------------------------------------

SELECT '--- SCENARIO 1: Insert standard valid student ---' AS 'Test Run';
INSERT INTO students (student_name, age, marks) VALUES ('Aarav Baruah', 20, 85.50);

-- View students table to confirm insertion and auto-population of created_at
SELECT * FROM students;
-- View student_log table to confirm log creation
SELECT * FROM student_log;


SELECT '--- SCENARIO 2: Attempt insert with age < 18 (Should FAIL) ---' AS 'Test Run';
-- This statement is wrapped in a comment block so running the file as a script does not halt execution,
-- but the query is written exactly as it would be run:
/*
INSERT INTO students (student_name, age, marks) VALUES ('Minor Kid', 17, 90.00);
-- Expected Output: ERROR 1644 (45000): ERROR: Insertion blocked. Student age must be 18 or older.
*/


SELECT '--- SCENARIO 3: Attempt insert with marks < 0 (Should FAIL) ---' AS 'Test Run';
/*
INSERT INTO students (student_name, age, marks) VALUES ('Negative Marks', 19, -5.00);
-- Expected Output: ERROR 1644 (45000): ERROR: Insertion blocked. Marks cannot be less than 0.
*/


SELECT '--- SCENARIO 4: Attempt update with marks < 0 (Should FAIL) ---' AS 'Test Run';
/*
UPDATE students SET marks = -10.00 WHERE student_name = 'Aarav Baruah';
-- Expected Output: ERROR 1644 (45000): ERROR: Update blocked. Marks cannot be less than 0.
*/


SELECT '--- SCENARIO 5: Successful update with valid marks ---' AS 'Test Run';
UPDATE students SET marks = 92.00 WHERE student_name = 'Aarav Baruah';
-- Verify that update succeeded
SELECT * FROM students;
