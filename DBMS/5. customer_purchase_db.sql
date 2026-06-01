-- ==========================================
-- Q5. Customer Purchase Database (DDL & DML with Foreign Keys)
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q5;
USE dbms_lab_q5;

-- Drop tables if they exist (in reverse order of foreign keys)
DROP TABLE IF EXISTS Purchase;
DROP TABLE IF EXISTS Item;
DROP TABLE IF EXISTS Customer;

-- 1. Create Customer Table
CREATE TABLE Customer (
    c_id INT PRIMARY KEY,
    c_name VARCHAR(100) NOT NULL,
    address VARCHAR(200) NOT NULL
);

-- 2. Create Item Table
CREATE TABLE Item (
    i_code INT PRIMARY KEY,
    i_name VARCHAR(100) NOT NULL,
    price DECIMAL(10, 2) NOT NULL
);

-- 3. Create Purchase Table with Foreign Keys
CREATE TABLE Purchase (
    p_id INT PRIMARY KEY,
    c_id INT,
    i_code INT,
    qty INT NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (c_id) REFERENCES Customer(c_id) ON DELETE CASCADE,
    FOREIGN KEY (i_code) REFERENCES Item(i_code) ON DELETE CASCADE
);

-- Insert sample Customers
INSERT INTO Customer (c_id, c_name, address) VALUES
(1, 'Aditya Baruah', 'Guwahati'),
(2, 'Barnali Sen', 'Jorhat'),
(3, 'Chayanika Devi', 'Tezpur'),
(4, 'Deepankar Roy', 'Silchar'); -- This customer will have no purchases to satisfy part (c)

-- Insert sample Items
INSERT INTO Item (i_code, i_name, price) VALUES
(101, 'Wireless Mouse', 800.00),
(102, 'Mechanical Keyboard', 2500.00),
(103, 'Gaming Headset', 1800.00),
(104, 'LED Monitor', 12000.00);

-- Insert sample Purchases
INSERT INTO Purchase (p_id, c_id, i_code, qty, date) VALUES
-- Purchases in February
(501, 1, 101, 3, '2026-02-10'), -- Aditya buys 3 Mouse (Total 2400)
(502, 2, 102, 2, '2026-02-14'), -- Barnali buys 2 Keyboards (Total 5000)
(503, 1, 102, 1, '2026-02-18'), -- Aditya buys 1 Keyboard (Total 2500)
-- Purchases in other months
(504, 3, 104, 1, '2026-01-20'), -- Chayanika buys 1 Monitor (Total 12000)
(505, 2, 104, 1, '2026-03-05'); -- Barnali buys 1 Monitor (Total 12000)

-- Show initial database states
SELECT '--- Customers ---' AS 'Message'; SELECT * FROM Customer;
SELECT '--- Items ---' AS 'Message'; SELECT * FROM Item;
SELECT '--- Purchases ---' AS 'Message'; SELECT * FROM Purchase;

-- -------------------------------------------------------------------------
-- a) Find the name of the customer who has done the maximum purchase (in terms of total money spent).
-- -------------------------------------------------------------------------
SELECT '--- Customer with Maximum Total Spend ---' AS 'Query a';
SELECT c.c_name, SUM(p.qty * i.price) AS total_spent
FROM Customer c
JOIN Purchase p ON c.c_id = p.c_id
JOIN Item i ON p.i_code = i.i_code
GROUP BY c.c_id, c.c_name
HAVING total_spent = (
    SELECT MAX(spent)
    FROM (
        SELECT SUM(p2.qty * i2.price) AS spent
        FROM Purchase p2
        JOIN Item i2 ON p2.i_code = i2.i_code
        GROUP BY p2.c_id
    ) AS sub
);

-- -------------------------------------------------------------------------
-- b) Display the name of the item that has been purchased maximum number of times
--    (maximum sum of quantity) in the month of February.
-- -------------------------------------------------------------------------
SELECT '--- Most Purchased Item in February ---' AS 'Query b';
SELECT i.i_name, SUM(p.qty) AS total_qty_purchased
FROM Item i
JOIN Purchase p ON i.i_code = p.i_code
WHERE MONTH(p.date) = 2
GROUP BY i.i_code, i.i_name
HAVING total_qty_purchased = (
    SELECT MAX(qty_sum)
    FROM (
        SELECT SUM(p2.qty) AS qty_sum
        FROM Purchase p2
        WHERE MONTH(p2.date) = 2
        GROUP BY p2.i_code
    ) AS sub
);

-- -------------------------------------------------------------------------
-- c) Display the name of the customer who did not purchase any item.
-- -------------------------------------------------------------------------
SELECT '--- Customers Who Made No Purchase ---' AS 'Query c';
SELECT c_name 
FROM Customer 
WHERE c_id NOT IN (SELECT DISTINCT c_id FROM Purchase);
