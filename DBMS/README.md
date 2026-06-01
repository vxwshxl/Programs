# Database Management Systems (DBMS) Laboratory

![Language](https://img.shields.io/badge/Language-MySQL-blue.svg)
![Course](https://img.shields.io/badge/Course-B.Tech%20CSE-orange.svg)
![Semester](https://img.shields.io/badge/Semester-4th-green.svg)
![University](https://img.shields.io/badge/University-Royal%20Global%20University-maroon.svg)

## Overview

This folder contains the Database Management System (DBMS) Lab Practical Queries and Databases in MySQL, implemented as part of the curriculum for the **Bachelor of Technology (B.Tech) in Computer Science and Engineering (CSE), 4th Semester** at **Royal Global University**.

The queries and schemas cover various database design principles, DDL, DML, joins, subqueries, stored procedures, triggers, and advanced database operations.

## How to Run

To run the queries in this repository, ensure you have a MySQL server installed and running.

1. Connect to your MySQL server:
   ```bash
   mysql -u your_username -p
   ```
2. Create and select a database if required (each script automatically creates its own isolated database namespace, e.g., `dbms_lab_q2`, `dbms_lab_q3` to avoid conflicts):
   ```sql
   CREATE DATABASE IF NOT EXISTS dbms_lab;
   USE dbms_lab;
   ```
3. Execute any `.sql` file using the `source` command or import it through your preferred GUI (like MySQL Workbench, phpMyAdmin, or DBeaver):
   ```sql
   SOURCE path/to/filename.sql;
   ```

## Experiments List

| Sl. No. | Experiment / Query Set Description | Status | File |
|---------|-----------------------------------|--------|------|
| 2       | Employee Database & Basic HR/Salary Queries | Completed | [2. employee_db.sql](./2.%20employee_db.sql) |
| 3       | Employee Salary Computations (DA, TA, HRA, TAX, GROSS, NET) | Completed | [3. employee_pay_computation.sql](./3.%20employee_pay_computation.sql) |
| 4       | Library Management System Queries (Subqueries, Joins, Date math) | Completed | [4. library_db.sql](./4.%20library_db.sql) |
| 5       | Customer Purchase Database & Aggregations (Foreign Keys, Joins) | Completed | [5. customer_purchase_db.sql](./5.%20customer_purchase_db.sql) |
| 6       | Movie Review System Schema (LEFT JOIN, LIMIT, AVG Rating) | Completed | [6. movie_review_system.sql](./6.%20movie_review_system.sql) |
| 7       | Library Joins, UNION operations & Referential Integrity | Completed | [7. library_joins_union.sql](./7.%20library_joins_union.sql) |
| 8       | Stored Procedures (Arithmetic, Max Salary, Subject Enrollments Count) | Completed | [8. stored_procedures.sql](./8.%20stored_procedures.sql) |
| 9       | Student Triggers (Logging inserts, Age & Marks validation) | Completed | [9. student_triggers.sql](./9.%20student_triggers.sql) |
| 10      | Employee Salary Update Validation Trigger | Completed | [10. employee_salary_trigger.sql](./10.%20employee_salary_trigger.sql) |

---

## Original Assignment Questions
The original question statements provided as individual lab assignments are archived in the [Q2_to_Q10_questions](./Q2_to_Q10_questions) directory.

---

## Disclaimer

These programs and queries are intended for educational purposes and reference. Students are encouraged to study the logic and implement their own solutions.
