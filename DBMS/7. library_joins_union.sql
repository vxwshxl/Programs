-- ==========================================
-- Q7. Library Management with Joins, Union & Integrity Constraints
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q7;
USE dbms_lab_q7;

-- Drop tables if they exist (in reverse order of foreign keys)
DROP TABLE IF EXISTS Borrowed_Books;
DROP TABLE IF EXISTS Books;
DROP TABLE IF EXISTS Categories;

-- 1. Create Categories Table
CREATE TABLE Categories (
    category_id INT PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL
);

-- 2. Create Books Table
CREATE TABLE Books (
    book_id INT PRIMARY KEY,
    title VARCHAR(150) NOT NULL,
    author VARCHAR(100) NOT NULL,
    category_id INT,
    FOREIGN KEY (category_id) REFERENCES Categories(category_id) ON DELETE CASCADE
);

-- 3. Create Borrowed_Books Table
CREATE TABLE Borrowed_Books (
    borrow_id INT PRIMARY KEY,
    book_id INT,
    member_name VARCHAR(100) NOT NULL,
    borrow_date DATE NOT NULL,
    FOREIGN KEY (book_id) REFERENCES Books(book_id) ON DELETE CASCADE
);

-- Insert sample Categories
INSERT INTO Categories (category_id, category_name) VALUES
(1, 'Science'),
(2, 'Fiction'),
(3, 'History'),
(4, 'Biography');

-- Insert sample Books
INSERT INTO Books (book_id, title, author, category_id) VALUES
(101, 'A Brief History of Time', 'Stephen Hawking', 1), -- Science
(102, 'The Grand Design', 'Stephen Hawking', 1),        -- Science
(103, 'To Kill a Mockingbird', 'Harper Lee', 2),          -- Fiction
(104, 'Sapiens', 'Yuval Noah Harari', 3),               -- History
(105, 'Steve Jobs', 'Walter Isaacson', 4),              -- Biography
(106, 'The Origin of Species', 'Charles Darwin', 1);    -- Science (unborrowed)

-- Insert sample Borrowed_Books
INSERT INTO Borrowed_Books (borrow_id, book_id, member_name, borrow_date) VALUES
(501, 101, 'John', '2026-05-01'),   -- Stephen Hawking book borrowed by John
(502, 103, 'Jane', '2026-05-02'),   -- Harper Lee book borrowed by Jane
(503, 104, 'John', '2026-05-03'),   -- Yuval Noah Harari book borrowed by John
(504, 105, 'Robert', '2026-05-05'); -- Walter Isaacson book borrowed by Robert

-- Show the active tables
SELECT '--- Categories ---' AS 'Message'; SELECT * FROM Categories;
SELECT '--- Books ---' AS 'Message'; SELECT * FROM Books;
SELECT '--- Borrowed Books ---' AS 'Message'; SELECT * FROM Borrowed_Books;

-- -------------------------------------------------------------------------
-- i) Fetch the list of books borrowed by members, along with their category names.
--    Use INNER JOIN on Books, Categories, and Borrowed_Books.
-- -------------------------------------------------------------------------
SELECT '--- Borrowed Books with Categories (INNER JOIN) ---' AS 'Query i';
SELECT 
    b.title, 
    b.author, 
    c.category_name, 
    bb.member_name, 
    bb.borrow_date
FROM Borrowed_Books bb
INNER JOIN Books b ON bb.book_id = b.book_id
INNER JOIN Categories c ON b.category_id = c.category_id;

-- -------------------------------------------------------------------------
-- ii) Find all the books that are not currently borrowed by any member.
--     Use LEFT JOIN on Books and Borrowed_Books.
-- -------------------------------------------------------------------------
SELECT '--- Unborrowed Books (LEFT JOIN) ---' AS 'Query ii';
SELECT 
    b.book_id, 
    b.title, 
    b.author
FROM Books b
LEFT JOIN Borrowed_Books bb ON b.book_id = bb.book_id
WHERE bb.book_id IS NULL;

-- -------------------------------------------------------------------------
-- iii) Combine the two datasets using the UNION operator:
--      - The names of all authors of books in the Science category.
--      - The names of all authors of books borrowed by members with name John.
-- -------------------------------------------------------------------------
SELECT '--- Combined Author List (UNION) ---' AS 'Query iii';
SELECT b.author
FROM Books b
JOIN Categories c ON b.category_id = c.category_id
WHERE c.category_name = 'Science'

UNION

SELECT b.author
FROM Books b
JOIN Borrowed_Books bb ON b.book_id = bb.book_id
WHERE bb.member_name = 'John';

-- -------------------------------------------------------------------------
-- iv) Assume adding a new book to the Books table. Write one SQL statement to
--     insert the record ensuring category_id matches an existing category_id.
-- -------------------------------------------------------------------------
SELECT '--- Adding new book (Foreign Key Validation) ---' AS 'Query iv';

-- Correct Insert: category_id = 1 (Science) exists
INSERT INTO Books (book_id, title, author, category_id) VALUES 
(107, 'Cosmos', 'Carl Sagan', 1);

-- Verify the insertion
SELECT * FROM Books WHERE book_id = 107;

/*
=============================================================================
EXPLANATION OF FOREIGN KEY CONSTRAINTS AND DATA INTEGRITY:
=============================================================================
A Foreign Key (FK) constraint establishes a link between two tables, ensuring 
Referential Integrity. In this schema:
1. `category_id` in the `Books` table references `category_id` in the `Categories` table.
2. When we attempt to insert a new book with a `category_id` (e.g., 1), the MySQL engine 
   automatically checks if a record with `category_id = 1` exists in the `Categories` table.
3. If we try to insert a book with a non-existent category (e.g., `category_id = 99`):
   
   INSERT INTO Books (book_id, title, author, category_id) 
   VALUES (108, 'Fake Book', 'Fake Author', 99);
   
   MySQL will raise an error and block the transaction:
   "ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails..."

This prevents "orphan" records in the database, ensuring that every book always 
belongs to a valid and existing category.
=============================================================================
*/
