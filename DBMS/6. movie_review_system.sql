-- ==========================================
-- Q6. Movie Review System Database
-- ==========================================

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS dbms_lab_q6;
USE dbms_lab_q6;

-- Drop tables if they exist (in reverse order of foreign keys)
DROP TABLE IF EXISTS Reviews;
DROP TABLE IF EXISTS Movies;

-- 1. Create Movies Table
CREATE TABLE Movies (
    movie_id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(150) NOT NULL,
    genre VARCHAR(50) NOT NULL,
    release_year INT NOT NULL
);

-- 2. Create Reviews Table with Foreign Key & Rating Check Constraint
CREATE TABLE Reviews (
    review_id INT PRIMARY KEY AUTO_INCREMENT,
    movie_id INT,
    reviewer_name VARCHAR(100) NOT NULL,
    rating INT NOT NULL CHECK (rating BETWEEN 1 AND 5),
    review_date DATE NOT NULL,
    FOREIGN KEY (movie_id) REFERENCES Movies(movie_id) ON DELETE CASCADE
);

-- Insert 5 movies
INSERT INTO Movies (movie_id, title, genre, release_year) VALUES
(1, 'Inception', 'Sci-Fi', 2010),
(2, 'The Dark Knight', 'Action', 2008),
(3, 'Interstellar', 'Sci-Fi', 2014),
(4, 'Pulp Fiction', 'Crime', 1994),
(5, 'The Shawshank Redemption', 'Drama', 1994);

-- Insert 10 reviews
INSERT INTO Reviews (movie_id, reviewer_name, rating, review_date) VALUES
(1, 'Alice Smith', 5, '2026-05-01'),
(1, 'Bob Jones', 4, '2026-05-15'),
(2, 'Charlie Brown', 5, '2026-05-20'),
(2, 'David Miller', 5, '2026-05-10'),
(3, 'Emily Watson', 4, '2026-05-18'),
(3, 'Frank Castle', 3, '2026-05-22'),
(4, 'Grace Hopper', 5, '2026-04-30'),
(4, 'Henry Cavill', 4, '2026-05-05'),
(5, 'Ivy League', 5, '2026-05-25'),
(5, 'Jack Reacher', 5, '2026-05-27');

-- Show database state
SELECT '--- Initial Movies ---' AS 'Message'; SELECT * FROM Movies;
SELECT '--- Initial Reviews ---' AS 'Message'; SELECT * FROM Reviews;

-- -------------------------------------------------------------------------
-- 3. Query 1: List all movie titles along with their genres and average rating.
--    We use LEFT JOIN so movies without reviews (if any) are not excluded.
-- -------------------------------------------------------------------------
SELECT '--- Movies with Average Ratings ---' AS 'Query 1';
SELECT m.title, m.genre, ROUND(AVG(r.rating), 2) AS average_rating
FROM Movies m
LEFT JOIN Reviews r ON m.movie_id = r.movie_id
GROUP BY m.movie_id, m.title, m.genre;

-- -------------------------------------------------------------------------
-- 4. Query 2: List the 3 most recently reviewed movies. Use the LIMIT clause.
--    We group by movie to avoid duplicates, find the maximum review date,
--    and sort by it descending to get the top 3.
-- -------------------------------------------------------------------------
SELECT '--- 3 Most Recently Reviewed Movies ---' AS 'Query 2';
SELECT m.title, MAX(r.review_date) AS most_recent_review_date
FROM Movies m
JOIN Reviews r ON m.movie_id = r.movie_id
GROUP BY m.movie_id, m.title
ORDER BY most_recent_review_date DESC
LIMIT 3;
