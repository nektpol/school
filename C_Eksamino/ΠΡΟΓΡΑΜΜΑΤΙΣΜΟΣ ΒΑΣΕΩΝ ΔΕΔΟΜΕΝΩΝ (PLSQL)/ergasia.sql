CREATE TABLE categories (
    category_id NUMBER PRIMARY KEY,
    category_name VARCHAR2(100) NOT NULL
);

CREATE TABLE products (
    product_id NUMBER PRIMARY KEY,
    product_name VARCHAR2(100) NOT NULL,
    price NUMBER(8,2),
    stock NUMBER,
    category_id NUMBER,
    FOREIGN KEY (category_id) REFERENCES categories (category_id)
);

INSERT INTO categories(category_id, category_name) VALUES 
    (1, 'Υπολογιστές'),
    (2, 'Κινητά'),
    (3, 'Περιφερειακά');

INSERT INTO products(product_id, product_name, price, stock, category_id) VALUES 
    (1, 'Laptop Lenovo',850.00,12,1),
    (2, 'Desktop HP',650.00,5,1),
    (3, 'Samsung Galaxy',420.00,0,2),
    (4, 'iPhone', 950.00,8,2),
    (5, 'Logitech Mouse', 35.00,25,3),
    (6, 'Mechanical Keyboard', 120.00,3,3);

SELECT * FROM products;

SELECT * FROM categories;


SET SERVEROUTPUT ON;

DECLARE 
    v_product_id NUMBER := 100;
    v_product_name VARCHAR2(100);
    v_price NUMBER(8,2);
    v_stock NUMBER;
    v_category_name VARCHAR2(100);
BEGIN 
    SELECT p.product_name, p.price, p.stock, c.category_name
    INTO v_product_name,v_price, v_stock, v_category_name
    FROM products p 
    INNER JOIN categories c
    ON p.category_id = c.category_id
    WHERE p.product_id = v_product_id;

    DBMS_OUTPUT.PUT_LINE('Προϊόν: ' || v_product_name);
    DBMS_OUTPUT.PUT_LINE('Τιμή (€): ' || v_price);
    DBMS_OUTPUT.PUT_LINE('Απόθεμα: ' || v_stock);
    DBMS_OUTPUT.PUT_LINE('Kατηγορία: ' || v_category_name);

    IF v_price >= 800  THEN 
        DBMS_OUTPUT.PUT_LINE('Ακριβό προϊόν');
    ELSIF v_price >= 300 THEN
        DBMS_OUTPUT.PUT_LINE('Μεσαίας τιμής');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Οικονομικό προϊόν');
    END IF;

    IF v_stock >= 8  THEN 
        DBMS_OUTPUT.PUT_LINE('Άμεσα διαθέσιμο');
    ELSIF v_price >= 1 THEN
        DBMS_OUTPUT.PUT_LINE('Περιορισμένο απόθεμα');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Μη διαθέσιμο');
    END IF;

EXCEPTION 
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Σφάλμα: Το προϊόν δεν βρέθηκε!');
END;
/