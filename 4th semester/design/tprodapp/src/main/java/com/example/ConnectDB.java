package com.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import com.example.controller.Product;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.sql.SQLException;

public class ConnectDB {
    private ObservableList<Product> products = FXCollections.observableArrayList();
    protected Connection connection = null;
    protected Statement statement = null;

    private void addProduct(Product product) {
        products.add(product);
    }

    // connect to sqlite database from my local path
    public void initDB() {
        if (connection == null || statement == null)
            try {
                connection = DriverManager.getConnection("jdbc:sqlite:data.db");
                statement = connection.createStatement();

                System.out.println("Database setup completed successfully.");

            } catch (SQLException e) {
                // if the error message is "out of memory",
                // it probably means no database file is found
                e.printStackTrace(System.err);
                closeConnection();
            }
        else {
            System.err.println("Connection already established.");
        }
    }

    public ObservableList<Product> getProducts() {
        try {
            clearProducts();
            ResultSet rs = statement.executeQuery("SELECT * FROM products;");
            while (rs.next()) {
                Product p = new Product(
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("category"),
                        rs.getDouble("price"),
                        rs.getInt("quantity"));
                addProduct(p);
            }
        } catch (Exception e) {
            e.printStackTrace(System.err);
            closeConnection();
        }

        return products;
    }

    public Product getProductById(int id) {
        for (Product p : products) {
            if (p.getId() == id) {
                return p;
            }
        }
        return null;
    }

    private void clearProducts() {
        products.clear();
    }

    public void uploadProduct(Product product) {
        try {
            String sql = "INSERT INTO products (name, category, price, quantity) VALUES (?, ?, ?, ?)";
            PreparedStatement pstmt = connection.prepareStatement(sql);
            pstmt.setString(1, product.getName());
            pstmt.setString(2, product.getCategory());
            pstmt.setDouble(3, product.getPrice());
            pstmt.setInt(4, product.getQuantity());
            if (pstmt.executeUpdate() > 0) {
                product = new Product(
                        pstmt.getGeneratedKeys().getInt(1), // Get the generated ID
                        product.getName(),
                        product.getCategory(),
                        product.getPrice(),
                        product.getQuantity());
                System.out.println("Product added successfully: " + product);
            } else {
                System.err.println("Failed to add product: " + product);
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
            closeConnection();
        }
    }

    protected void closeConnection() {
        try {
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
        } finally {
            System.out.println("Connection closed.");
        }
    }
}
