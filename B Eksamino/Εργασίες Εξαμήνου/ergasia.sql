CREATE DATABASE cafe_orders_db;
USE cafe_orders_db;

CREATE TABLE tables (
    id INT PRIMARY KEY AUTO_INCREMENT,
    table_number INT NOT NULL,
    seats INT,
    location VARCHAR(50)
);

CREATE TABLE products (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    category VARCHAR(50),
    price DECIMAL(6, 2) NOT NULL,
    available BOOLEAN
);

CREATE TABLE orders (
    id INT PRIMARY KEY AUTO_INCREMENT,
    table_id INT,
    product_id INT,
    quantity INT,
    order_date DATE,

    FOREIGN KEY (table_id) REFERENCES tables(id),
    FOREIGN KEY (product_id) REFERENCES products(id)
);

INSERT INTO tables (table_number, seats, location) VALUES
(1, 2, 'indoor'),
(2, 4, 'indoor'),
(3, 4, 'outdoor'),
(4, 6, 'terrace'),
(5, 2, 'outdoor');

INSERT INTO products (name, category, price, available) VALUES
('Espresso', 'coffee', 2.50, TRUE),
('Cappuccino', 'coffee', 3.20, TRUE),
('Freddo Espresso', 'coffee', 3.00, TRUE),
('Orange Juice', 'beverage', 3.50, TRUE),
('Lemonade', 'beverage', 2.80, TRUE),
('Chocolate Cake', 'dessert', 4.50, TRUE),
('Croissant', 'snack', 2.20, TRUE),
('Club Sandwich', 'snack', 5.90, TRUE);

INSERT INTO orders (table_id, product_id, quantity, order_date) VALUES
(1, 1, 2, '2026-03-10'),
(2, 2, 1, '2026-03-10'),
(3, 3, 2, '2026-03-10'),
(4, 4, 3, '2026-03-11'),
(5, 6, 1, '2026-03-11'),
(1, 7, 2, '2026-03-11'),
(2, 5, 2, '2026-03-12'),
(3, 8, 1, '2026-03-12'),
(4, 2, 2, '2026-03-12'),
(5, 1, 1, '2026-03-13');

