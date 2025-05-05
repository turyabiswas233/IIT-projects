-- DROP table
DROP TABLE borrower;
DROP TABLE depositor;
DROP TABLE loan;
DROP TABLE account;
DROP TABLE customer;
DROP TABLE branch;

-- create table

CREATE TABLE branch (
	branch_name varchar2(20),
	branch_city varchar2(20),
	assets number(8),
	constraint branch_name_pk primary key (branch_name)
);

CREATE TABLE customer (
	customer_name varchar2(20),
	customer_street varchar2(20),
	city varchar2(20),
	constraint cn_pk primary key (customer_name)
);

CREATE TABLE account (
	account_number varchar2(20),
	branch_name varchar2(20),
	balance number(20,2),
	constraint acc_num_pk primary key (account_number),
	constraint bn_ac_fk foreign key (branch_name)
	references branch (branch_name)
);

CREATE TABLE loan (
	loan_number varchar2(20),
	branch_name varchar2(20),
	amount number(20,2),
	constraint loan_num_pk primary key (loan_number),
	constraint bn_ln_fk foreign key (branch_name)
	references branch (branch_name)
);

CREATE TABLE depositor (
	customer_name varchar2(20),
	account_number varchar2(20),
	constraint cn_dep_fk foreign key (customer_name)
	references customer (customer_name),
	constraint ac_dep_fk foreign key (account_number)
	references account (account_number)
);

CREATE TABLE borrower (
	customer_name varchar2(20),
	loan_number varchar2(20),
	constraint cn_bor_fk foreign key (customer_name)
	references customer (customer_name),
	constraint ln_bor_fk foreign key (loan_number)
	references loan (loan_number)
);


describe branch;
describe customer;
describe account;
describe loan;
describe depositor;
describe borrower;



-- INSERT branch data
INSERT INTO branch VALUES ('Brighton', 'Brooklyn', 7100000);
INSERT INTO branch VALUES ('Downtown', 'Brooklyn', 9000000);
INSERT INTO branch VALUES ('Mainus', 'Horseneck', 400000);
INSERT INTO branch VALUES ('North Town', 'Rye', 3700000);
INSERT INTO branch VALUES ('Perryridge', 'Horseneck', 1700000);
INSERT INTO branch VALUES ('Pownal', 'Bennington', 300000);
INSERT INTO branch VALUES ('Redwood', 'Palo Alto', 2100000);
INSERT INTO branch VALUES ('Round Hill', 'Horseneck', 8000000);

SELECT * FROM branch;

-- INSERT customer data
INSERT INTO customer VALUES ('Adams', 'Spring', 'Pittsfield' );
INSERT INTO customer VALUES ('Brooks', 'Senator', 'Brooklyn' );
INSERT INTO customer VALUES ('Curry', 'North', 'Rye' );
INSERT INTO customer VALUES ('Glenn', 'Sand Hill', 'Woodside' );
INSERT INTO customer VALUES ('Green', 'Walnut', 'Stamform' );
INSERT INTO customer VALUES ('Hayes', 'Main', 'Harrison' );
INSERT INTO customer VALUES ('Johnson', 'Alma', 'Palo Alto' );
INSERT INTO customer VALUES ('Jones', 'Main', 'Harrison' );
INSERT INTO customer VALUES ('Lindsay', 'Park', 'Pittsfield' );
INSERT INTO customer VALUES ('Smith', 'North', 'Rye' );
INSERT INTO customer VALUES ('Turner', 'Putnam', 'Stamform' );
INSERT INTO customer VALUES ('Williams', 'Nassau', 'Princeton' );

SELECT * FROM customer;

-- INSERT account data
INSERT INTO account VALUES ('A-101', 'Downtown', 500);
INSERT INTO account VALUES ('A-102', 'Perryridge', 400);
INSERT INTO account VALUES ('A-201', 'Brighton', 900);
INSERT INTO account VALUES ('A-215', 'Mainus', 700);
INSERT INTO account VALUES ('A-217', 'Brighton', 750);
INSERT INTO account VALUES ('A-222', 'Redwood', 700);
INSERT INTO account VALUES ('A-305', 'Round Hill', 350);

SELECT * FROM account;


-- INSERT depositor data

INSERT INTO depositor VALUES ('Hayes', 'A-102');
INSERT INTO depositor VALUES ('Johnson', 'A-101');
INSERT INTO depositor VALUES ('Johnson', 'A-201');
INSERT INTO depositor VALUES ('Jones', 'A-217');
INSERT INTO depositor VALUES ('Lindsay', 'A-222');
INSERT INTO depositor VALUES ('Smith', 'A-215');
INSERT INTO depositor VALUES ('Turner', 'A-305');

SELECT * FROM depositor;


-- INSERT loan data

INSERT INTO loan VALUES ('L-11','Round Hill',900);
INSERT INTO loan VALUES ('L-14','Downtown',1500);
INSERT INTO loan VALUES ('L-15','Perryridge',1500);
INSERT INTO loan VALUES ('L-16','Perryridge',1300);
INSERT INTO loan VALUES ('L-17','Downtown',1000);
INSERT INTO loan VALUES ('L-23','Redwood',2000);
INSERT INTO loan VALUES ('L-93','Mainus',500);

SELECT * FROM loan;


-- INSERT borrower data

INSERT INTO borrower VALUES ('Adams','L-16');
INSERT INTO borrower VALUES ('Curry','L-93');
INSERT INTO borrower VALUES ('Hayes','L-15');
INSERT INTO borrower VALUES ('Jackson','L-14');
INSERT INTO borrower VALUES ('Jones','L-17');
INSERT INTO borrower VALUES ('Smith','L-11');
INSERT INTO borrower VALUES ('Smith','L-23');
INSERT INTO borrower VALUES ('Williams','L-17');

SELECT * FROM borrower;











