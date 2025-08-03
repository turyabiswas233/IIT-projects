package com.example.utils;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.example.ConnectDB;
import com.example.models.Product;

import javafx.collections.ObservableList;

public class ProductFactory {
    private ObservableList<Product> products = javafx.collections.FXCollections.observableArrayList();
    private static ProductFactory instance;

    private ProductFactory() {
        System.out.println("Created new Product Factory");
    }

    private void addProduct(Product product) {
        products.add(product);
    }

    public ObservableList<Product> getProducts() {
        // ConnectDB.initDB();
        try (PreparedStatement pstmt = ConnectDB.getConnection().prepareStatement("SELECT * FROM products;")) {
            products.clear();

            ResultSet rs = pstmt.executeQuery();
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

    public boolean deleteProductById(int id) {
        boolean isSuccess = false;
        try {

            ConnectDB.initDB();

            String sql = "DELETE FROM products WHERE id = ?";
            PreparedStatement pstmt = ConnectDB.getConnection().prepareStatement(sql);
            pstmt.setInt(1, id);
            if (pstmt.executeUpdate() > 0) {
                System.out.println("Product with ID " + id + " deleted successfully.");
                products.removeIf(p -> p.getId() == id); // Remove from cache
                isSuccess = true;
            } else {
                System.err.println("Failed to delete product with ID: " + id);
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
        }
        return isSuccess;
    }

    public boolean uploadProduct(Product product) {
        boolean isSuccess = false;
        if (product == null) {
            System.err.println("Product is null, cannot upload.");
            return isSuccess;
        }

        if (ConnectDB.getConnection() == null) {
            ConnectDB.initDB();
        }
        String sql = "INSERT INTO products (name, category, price, quantity) VALUES (?, ?, ?, ?)";
        try (PreparedStatement pstmt = ConnectDB.getConnection().prepareStatement(sql);) {

            // pstmt.setInt(1, getNextProductId()); // Use the next product ID
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
                isSuccess = true;
                addProduct(product);
            } else {
                System.err.println("Failed to add product: " + product);
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
        }
        return isSuccess;
    }

    public int getNextProductId() {
        if (products.isEmpty()) {
            return 1; // Start from 1 if no products exist
        } else {
            return products.stream().mapToInt(Product::getId).max().orElse(0) + 1;
        }
    }

    public static ProductFactory getInstance() {
        synchronized (ProductFactory.class) {
            if (instance == null) {
                instance = new ProductFactory();
            }
            ConnectDB.initDB();
        }
        return instance;
    }
}
