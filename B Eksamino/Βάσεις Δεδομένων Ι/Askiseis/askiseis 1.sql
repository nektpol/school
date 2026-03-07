-- askisi1
CREATE DATABASE askiseis;
USE askiseis;

CREATE TABLE students (
    id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    age INT,
    grade DECIMAL(4, 2),
    active BOOLEAN NOT NULL 
);

-- askisi2
INSERT INTO students (first_name, last_name, age, grade, active) VALUES
('Maria','Papadopoulou',20,7.50,true),
('Giannis','Ioannou',22,4.80,true),
('Eleni','Kosta',NULL,8.10,true),
('Nikos','Nikolaou',19,6.20,false),
('Anna','Georgiou',24,NULL,true),
('Petros','Dimitriou',NULL,3.90,false),
('Sofia','Pappas',18,9.20,true),
('Kostas','Karas',26,5.00,true);

-- askisi3
SELECT * FROM `students`

-- askisi4
SELECT first_name,last_name,grade FROM `students`

-- askisi5
SELECT * FROM `students` WHERE age>20

-- askisi6
SELECT * FROM `students` WHERE active=1 AND grade>=7

-- askisi7
SELECT * FROM `students` WHERE grade<5 OR active=0

-- askisi8
SELECT * FROM `students` WHERE age IS NULL

-- askisi9
UPDATE `students` SET grade=5.5 WHERE id=2

-- askisi10
UPDATE `students` SET active=0 WHERE age>=25

