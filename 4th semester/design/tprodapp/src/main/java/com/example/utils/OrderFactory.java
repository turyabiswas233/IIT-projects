package com.example.utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.example.ConnectDB;
import com.example.models.Customer;
import com.example.models.Order;
import com.example.models.Product;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class OrderFactory {
    private static OrderFactory instance;
    private static ObservableList<Customer> customerList = FXCollections.observableArrayList();
    private static ObservableList<Product> productList = FXCollections.observableArrayList();

    private OrderFactory() {
        System.out.println("Created new Order Factory");
    }

    public ObservableList<Customer> loadCustomers() {
        String sql = "SELECT id, name FROM customers";

        try (Connection conn = ConnectDB.getConnection();
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                customerList.add(new Customer(rs.getInt("id"), rs.getString("name"), rs.getString("phone")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return customerList;
    }

    public ObservableList<Product> loadProducts() {
        String sql = "SELECT id, name, price FROM products WHERE quantity > 0";

        try (Connection conn = ConnectDB.getConnection();
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                productList.add(new Product(rs.getString("name"), rs.getString("category"), rs.getDouble("price"),
                        rs.getInt("quantity")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return productList;
    }

    public boolean createOrder(Customer selectedCustomer, Product selectedProduct, Integer quantity) {
        boolean status = true;

        if (selectedCustomer == null || selectedProduct == null) {
            status = false;
        } else {
            String orderSql = "INSERT INTO orders(customer_id, product_id, quantity) VALUES(?,?,?)";
            String updateProductSql = "UPDATE products SET quantity = quantity - ? WHERE id = ?";

            try (Connection conn = ConnectDB.getConnection()) {
                conn.setAutoCommit(false);

                try (PreparedStatement pstmtOrder = conn.prepareStatement(orderSql);
                        PreparedStatement pstmtUpdate = conn.prepareStatement(updateProductSql)) {

                    pstmtOrder.setInt(1, selectedCustomer.getId());
                    pstmtOrder.setInt(2, selectedProduct.getId());
                    pstmtOrder.setInt(3, quantity);
                    pstmtOrder.executeUpdate();

                    pstmtUpdate.setInt(1, quantity);
                    pstmtUpdate.setInt(2, selectedProduct.getId());
                    pstmtUpdate.executeUpdate();

                    conn.commit();

                    System.out.println("Successfully created an ORDER");
                    // Refresh product list as quantity has changed
                    productList.clear();
                    loadProducts();

                } catch (SQLException e) {
                    conn.rollback(); // Rollback on error
                    throw e;
                }

            } catch (SQLException e) {
                e.printStackTrace();
                status = false;
            }

        }

        return status;
    }

    public ObservableList<Order> loadOrders() {
        ObservableList<Order> orderList = FXCollections.observableArrayList();
        String sql = "SELECT o.id, o.customer_id, o.product_id, o.quantity, o.order_date, " +
                "c.name as customer_name, p.name as product_name, p.price " +
                "FROM orders o " +
                "JOIN customers c ON o.customer_id = c.id " +
                "JOIN products p ON o.product_id = p.id " +
                "ORDER BY o.order_date DESC";

        try {
            PreparedStatement stmt = ConnectDB.getConnection().prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                double totalPrice = rs.getDouble("price") * rs.getInt("quantity");
                Order order = new Order(
                        rs.getInt("customer_id"),
                        rs.getInt("product_id"),
                        rs.getInt("quantity"),
                        rs.getString("order_date"),
                        rs.getString("customer_name"),
                        rs.getString("product_name"),
                        totalPrice);
                order.setId(rs.getInt("id"));
                orderList.add(order);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return orderList;
    }

    public static ObservableList<Customer> loadCustomersWithPhone() {
        ObservableList<Customer> customers = FXCollections.observableArrayList();
        String sql = "SELECT id, name, phone FROM customers";
        try (Connection conn = ConnectDB.getConnection();
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                customers.add(new Customer(rs.getInt("id"), rs.getString("name"), rs.getString("phone")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return customers;
    }

    public static ObservableList<Product> loadAvailableProducts() {
        ObservableList<Product> products = FXCollections.observableArrayList();
        String sql = "SELECT id, name, category, price, quantity FROM products WHERE quantity > 0";

        try (Connection conn = ConnectDB.getConnection();
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                products.add(new Product(rs.getInt("id"), rs.getString("name"),
                        rs.getString("category"), rs.getDouble("price"), rs.getInt("quantity")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return products;
    }

    public static OrderFactory getInstance() {
        synchronized (OrderFactory.class) {
            if (instance == null) {
                instance = new OrderFactory();
            }
            ConnectDB.initDB();
        }
        return instance;
    }
}
