-- ==========================================
-- Q4. Library Management System Relational Database
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q4;
USE dbms_lab_q4;

-- Drop tables if they exist (in reverse order of foreign keys)
DROP TABLE IF EXISTS Issue_Return;
DROP TABLE IF EXISTS Members;
DROP TABLE IF EXISTS Books;

-- 1. Create Books Table
CREATE TABLE Books (
    b_id INT PRIMARY KEY,
    b_name VARCHAR(150) NOT NULL,
    author VARCHAR(100) NOT NULL,
    purchase_date DATE NOT NULL,
    cost DECIMAL(8, 2) NOT NULL
);

-- 2. Create Members Table
CREATE TABLE Members (
    m_id INT PRIMARY KEY,
    m_name VARCHAR(100) NOT NULL,
    address VARCHAR(200),
    phone VARCHAR(15),
    birthdate DATE NOT NULL
);

-- 3. Create Issue_Return Table
CREATE TABLE Issue_Return (
    b_id INT,
    m_id INT,
    i_date DATE NOT NULL,
    r_date DATE DEFAULT NULL, -- NULL means the book is currently issued (not yet returned)
    PRIMARY KEY (b_id, m_id, i_date),
    FOREIGN KEY (b_id) REFERENCES Books(b_id) ON DELETE CASCADE,
    FOREIGN KEY (m_id) REFERENCES Members(m_id) ON DELETE CASCADE
);

-- Insert sample books
INSERT INTO Books (b_id, b_name, author, purchase_date, cost) VALUES
(1, 'Database System Concepts', 'S. Sudarshan', '2023-01-15', 1200.00),
(2, 'Introduction to Algorithms', 'Thomas H. Cormen', '2022-06-10', 2500.00),
(3, 'Operating System Concepts', 'Avi Silberschatz', '2023-03-20', 1500.00),
(4, 'Computer Networks', 'Andrew S. Tanenbaum', '2024-02-12', 1800.00),
(5, 'Compilers: Principles, Techniques, and Tools', 'Alfred Aho', '2021-11-05', 2200.00),
(6, 'Software Engineering', 'Ian Sommerville', '2025-01-10', 950.00);

-- Insert sample members (including some with names starting with 'R', and birthdays before/after 1989-01-01)
INSERT INTO Members (m_id, m_name, address, phone, birthdate) VALUES
(201, 'Rohan Das', 'Guwahati, Assam', '9876543210', '1988-05-12'), -- Birthdate < 1989
(202, 'Rahul Sharma', 'Shillong, Meghalaya', '8765432109', '1990-10-22'), -- Birthdate >= 1989, Starts with R
(203, 'Priya Sen', 'Tezpur, Assam', '7654321098', '1985-02-15'), -- Birthdate < 1989
(204, 'Riya Baruah', 'Jorhat, Assam', '6543210987', '1995-12-05'), -- Birthdate >= 1989, Starts with R
(205, 'Amit Gupta', 'Dibrugarh, Assam', '9988776655', '1987-07-30'); -- Birthdate < 1989

-- Insert issue and return records
-- Let's construct these to carefully satisfy the query conditions
INSERT INTO Issue_Return (b_id, m_id, i_date, r_date) VALUES
(1, 201, '2026-01-10', '2026-01-20'), -- Issued to Rohan (R..., DoB < 1989)
(1, 203, '2026-02-05', NULL),         -- Issued to Priya (DoB < 1989), Currently Active (No return date)
(2, 202, '2026-01-15', '2026-01-25'), -- Issued to Rahul (R..., DoB >= 1989)
(3, 205, '2026-03-01', '2026-03-10'), -- Issued to Amit (DoB < 1989) only
(3, 201, '2026-04-05', NULL),         -- Issued to Rohan (DoB < 1989), Currently Active
(4, 204, '2026-02-20', NULL),         -- Issued to Riya (R..., DoB >= 1989)
(4, 202, '2026-03-15', '2026-03-25'); -- Issued to Rahul (R..., DoB >= 1989)
-- Book 5 is never issued
-- Book 6 is issued once to Rohan (DoB < 1989)
INSERT INTO Issue_Return (b_id, m_id, i_date, r_date) VALUES
(6, 201, '2026-05-01', '2026-05-15');

-- Show database state
SELECT '--- Initial Books ---' AS 'Message'; SELECT * FROM Books;
SELECT '--- Initial Members ---' AS 'Message'; SELECT * FROM Members;
SELECT '--- Initial Issue_Return ---' AS 'Message'; SELECT * FROM Issue_Return;

-- -------------------------------------------------------------------------
-- i) Find the authors of the books that have not been issued.
-- -------------------------------------------------------------------------
SELECT '--- Authors of Unissued Books ---' AS 'Query i';
SELECT DISTINCT author 
FROM Books 
WHERE b_id NOT IN (SELECT DISTINCT b_id FROM Issue_Return);

-- -------------------------------------------------------------------------
-- ii) Display the member IDs and number of books issued to that member.
-- (Assume that if a book does not have a return date, then it is issued.)
-- Note: We count active issues (r_date IS NULL).
-- -------------------------------------------------------------------------
SELECT '--- Member IDs and Active Issued Books Count ---' AS 'Query ii';
SELECT m_id, COUNT(*) AS active_issued_books
FROM Issue_Return
WHERE r_date IS NULL
GROUP BY m_id;

-- -------------------------------------------------------------------------
-- iii) Find the book that has been issued the minimum number of times.
-- Note: Includes books issued 0 times using a LEFT JOIN.
-- -------------------------------------------------------------------------
SELECT '--- Book(s) Issued Minimum Number of Times ---' AS 'Query iii';
SELECT b.b_id, b.b_name, COUNT(ir.b_id) AS issue_count
FROM Books b
LEFT JOIN Issue_Return ir ON b.b_id = ir.b_id
GROUP BY b.b_id, b.b_name
HAVING issue_count = (
    SELECT MIN(cnt)
    FROM (
        SELECT COUNT(ir2.b_id) AS cnt
        FROM Books b2
        LEFT JOIN Issue_Return ir2 ON b2.b_id = ir2.b_id
        GROUP BY b2.b_id
    ) AS sub
);

-- -------------------------------------------------------------------------
-- iv) Display the names and author of the books that have been issued at any time
-- to members whose name begins with 'R'.
-- -------------------------------------------------------------------------
SELECT '--- Books Issued to Members starting with R ---' AS 'Query iv';
SELECT DISTINCT b.b_name, b.author
FROM Books b
JOIN Issue_Return ir ON b.b_id = ir.b_id
JOIN Members m ON ir.m_id = m.m_id
WHERE m.m_name LIKE 'R%';

-- -------------------------------------------------------------------------
-- v) Display the name and cost of those books that have been issued to any member
-- whose date of birth is less than 01-01-1989, but not been issued to any member
-- having the birth date equal to or greater than 01-01-1989.
-- -------------------------------------------------------------------------
SELECT '--- Books Issued to DoB < 1989 but NOT DoB >= 1989 ---' AS 'Query v';
SELECT b_name, cost
FROM Books
WHERE b_id IN (
    SELECT ir.b_id 
    FROM Issue_Return ir
    JOIN Members m ON ir.m_id = m.m_id
    WHERE m.birthdate < '1989-01-01'
)
AND b_id NOT IN (
    SELECT ir.b_id 
    FROM Issue_Return ir
    JOIN Members m ON ir.m_id = m.m_id
    WHERE m.birthdate >= '1989-01-01'
);
