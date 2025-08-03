DROP TABLE IF EXISTS order_items;

DROP TABLE IF EXISTS orders;

DROP TABLE IF EXISTS products;

DROP TABLE IF EXISTS users;

DROP TABLE IF EXISTS employees;

DROP TABLE IF EXISTS customers;

CREATE TABLE
    users (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name VARCHAR(100) NOT NULL,
        email VARCHAR(100) NOT NULL,
        password VARCHAR(100) NOT NULL,
        role TEXT (10) NOT NULL
    );

CREATE TABLE
    employees (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name VARCHAR(100) NOT NULL,
        email VARCHAR(100) NOT NULL,
        phone TEXT (20) NOT NULL
    );

CREATE TABLE
    customers (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name VARCHAR(100) NOT NULL,
        phone TEXT (20) NOT NULL
    );

CREATE TABLE
    products (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name VARCHAR(100) NOT NULL,
        price DECIMAL(10, 2) NOT NULL,
        category VARCHAR(100),
        quantity INT NOT NULL
    );

CREATE TABLE
    orders (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        customer_id INT NOT NULL,
        product_id INT NOT NULL,
        quantity INT NOT NULL,
        order_date CURRENT_TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (customer_id) REFERENCES customers (id),
        FOREIGN KEY (product_id) REFERENCES products (id)
    );

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Product B', 9, 'Books', 50);

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Product C', 29, 'Clothing', 200);

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Product D', 49, 'Home & Kitchen', 75);

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Product E', 15, 'Sports', 150);

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Product F', 5, 'Toys', 300);

INSERT INTO
    products (name, price, category, quantity)
VALUES
    ('Pokemon Ball', 250, 'Toys', 300);

INSERT INTO
    users (name, email, password, role)
VALUES
    (
        'ADMIN',
        'admin@gmail.com',
        'admin',
        'super_admin'
    );

INSERT INTO
     users (name, email, password, role)
VALUES
    ('EM-1', 'employee@gmail.com', 'employee', 'employee');

INSERT INTO
    employees
VALUES
    (1, 'EM-1', 'employee@gmail.com', '1507');

INSERT INTO
    customers (name, phone)
VALUES
    ('Turya', '01540153659');

INSERT INTO
    customers (name, phone)
VALUES
    ('Shuvra', '01969050601');

INSERT INTO
    orders (customer_id, product_id, quantity)
VALUES
    (1, 2, 5);

INSERT INTO
    orders (customer_id, product_id, quantity)
VALUES
    (2, 6, 20);

--ADMIN:  admin@gmail.com, admin
--EMPLOY: employee@gmail.com, employee

-- select O.id as 'O_ID', C.name as 'C_NAME', P.name as 'P_NAME', (P.price * O.quantity) as 'TOTAL PRICE' from orders O,customers C,products P where O.customer_id = C.id and P.id = O.product_id;