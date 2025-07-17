DROP TABLE IF EXISTS order_items;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS products;
DROP TABLE IF EXISTS users;

CREATE TABLE users (
        id AUTO PRIMARY KEY,
        name VARCHAR(100) NOT NULL,
        email VARCHAR(100) NOT NULL,
        password VARCHAR(100) NOT NULL,
        role VARCHAR(10) NOT NULL
    );
CREATE TABLE orders (
        id AUTO PRIMARY KEY,
        user_id INT NOT NULL,
        order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        status VARCHAR(50) NOT NULL,
        FOREIGN KEY (user_id) REFERENCES users (id)
    );
CREATE TABLE products (
        id AUTO PRIMARY KEY,
        name VARCHAR(100) NOT NULL,
        price DECIMAL(10, 2) NOT NULL,
        category VARCHAR(100),
        quantity INT NOT NULL
    );
CREATE TABLE order_items (
        id SERIAL AUTO PRIMARY KEY,
        order_id INT NOT NULL,
        product_name VARCHAR(100) NOT NULL,
        quantity INT NOT NULL,
        price DECIMAL(10, 2) NOT NULL,
        FOREIGN KEY (order_id) REFERENCES orders (id)
    );
    
INSERT INTO products VALUES(1,'Product B',9,'Books',50);
INSERT INTO products VALUES(2,'Product C',29,'Clothing',200);
INSERT INTO products VALUES(3,'Product D',49,'Home & Kitchen',75);
INSERT INTO products VALUES(4,'Product E',15,'Sports',150);
INSERT INTO products VALUES(5,'Product F',5,'Toys',300);
INSERT INTO products VALUES(6,'Pokemon Ball',250,'Toys',300);

--ADMIN:  admin@gmail.com, admin
--EMPLOY: employee@gmail.com, employee