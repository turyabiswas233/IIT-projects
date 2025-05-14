drop table if exists order_items;

drop table if exists orders;

drop table if exists users;

CREATE TABLE
    users (
        id required SERIAL AUTO PRIMARY KEY,
        name VARCHAR(100) NOT NULL,
        email VARCHAR(100) NOT NULL
    );

-- create order table
CREATE TABLE
    orders (
        id SERIAL PRIMARY KEY,
        user_id INT NOT NULL,
        order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        status VARCHAR(50) NOT NULL,
        FOREIGN KEY (user_id) REFERENCES users (id)
    );

-- create order_items table
CREATE TABLE
    order_items (
        id SERIAL PRIMARY KEY,
        order_id INT NOT NULL,
        product_name VARCHAR(100) NOT NULL,
        quantity INT NOT NULL,
        price DECIMAL(10, 2) NOT NULL,
        FOREIGN KEY (order_id) REFERENCES orders (id)
    );

-- insert some random data into all tables
INSERT INTO
    users (id, name, email)
VALUES
    (1, 'John Doe', 'john@gmail.com'),
    (2, 'Jane Smith', 'jane@gmail.com');

INSERT INTO
    orders (user_id, order_date, status)
VALUES
    (1, '2023-10-01 10:00:00', 'shipped'),
    (2, '2023-10-02 11:00:00', 'pending');

INSERT INTO
    order_items (order_id, product_name, quantity, price)
VALUES
    (1, 'Product A', 2, 19.99),
    (1, 'Product B', 1, 9.99),
    (2, 'Product C', 3, 29.99);