CREATE TABLE departments (
    department_id NUMBER PRIMARY KEY,
    department_name VARCHAR2(100) NOT NULL
);

CREATE TABLE students(
    student_id NUMBER PRIMARY KEY,
    first_name VARCHAR2(50) NOT NULL,
    last_name VARCHAR2(50) NOT NULL,
    grade NUMBER(4,2),
    department_id NUMBER,
    FOREIGN KEY (department_id) REFERENCES departments (department_id)
);

INSERT INTO departments(department_id, department_name) VALUES 
    (1, 'Πληροφορική'),
    (2, 'Γραφιστική'),
    (3, 'Διοίκηση Επιχειρήσεων');

SELECT * FROM departments;

INSERT INTO students VALUES 
    (1, 'Giorgos', 'Papadopoulos', 18.5,1),
    (2, 'Maria','Nikolaou',16.5,1),
    (3,'Eleni','Kostantinou',19.5,1),
    (4,'Nikos','Georgiou',14.5,3);

SELECT * FROM students;

SELECT 
    s.first_name, 
    s.last_name, 
    s.grade,
    d.department_name
FROM students s 
INNER JOIN departments d
ON s.department_id = d.department_id;

SET SERVEROUTPUT ON;

DECLARE 
    v_name VARCHAR2(50);
    v_grade NUMBER(4.2);
BEGIN 
    SELECT first_name, grade
    INTO v_name,v_grade
    FROM students 
    WHERE student_id = 1;

    DBMS_OUTPUT.PUT_LINE('Onoma: ' || v_name);
    DBMS_OUTPUT.PUT_LINE('Vathmos: ' || v_grade);

END;
/

DECLARE 
    v_student_id NUMBER := 1;
    v_name VARCHAR2(50);
    v_grade NUMBER(4.2);
BEGIN 
    SELECT first_name, grade
    INTO v_name,v_grade
    FROM students 
    WHERE student_id = v_student_id;

    DBMS_OUTPUT.PUT_LINE('Onoma: ' || v_name);
    DBMS_OUTPUT.PUT_LINE('Vathmos: ' || v_grade);

    IF v_grade >= 18 THEN 
        DBMS_OUTPUT.PUT_LINE('Excelent');
    ELSIF v_grade >= 15 THEN
        DBMS_OUTPUT.PUT_LINE('Very Good');
    ELSIF v_grade >= 10 THEN 
        DBMS_OUTPUT.PUT_LINE('Good');
    ELSE
        DBMS_OUTPUT.PUT_LINE('FAILED');
    END IF;

EXCEPTION 
    WHEN NO_DATA_FOUND then
        DBMS_OUTPUT.PUT_LINE('Not Valid ID');


END;
/