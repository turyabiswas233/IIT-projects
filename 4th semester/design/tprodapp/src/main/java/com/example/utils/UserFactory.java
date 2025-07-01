package com.example.utils;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.example.ConnectDB;
import com.example.controller.AuthController;
import com.example.models.User;

import javafx.collections.ObservableList;

public class UserFactory {
    private static UserFactory instance = null;
    private static ObservableList<User> users = javafx.collections.FXCollections.observableArrayList();

    public ObservableList<User> getUsers() {
        try {
            loadUsers();
        } catch (Exception e) {
            System.err.println(e.getLocalizedMessage());
            e.printStackTrace();
        } finally {
        }
        return users;
    }

    private void loadUsers() {
        String query = "SELECT * FROM users";
        try (PreparedStatement statement = ConnectDB.getConnection().prepareStatement(query);
                ResultSet resultSet = statement.executeQuery()) {
            users.clear();
            while (resultSet.next()) {
                User user = new User(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getString("email"),
                        resultSet.getString("password"),
                        resultSet.getString("role"));
                users.add(user);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public boolean addUser(User user) {
        String query = "INSERT INTO users (name, email, password, role) VALUES (?, ?, ?, ?)";
        try (PreparedStatement statement = ConnectDB.getConnection().prepareStatement(query)) {
            statement.setString(1, user.getName().get());
            statement.setString(2, user.getEmail().get());
            statement.setString(3, user.getPassword().get());
            statement.setString(4, user.getRole().get());
            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                users.add(user);
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    
    public User getUser(String email) {
        for (User user : users) {
            if (user.getEmail().get().equals(email)) {
                return user;
            }
        }
        return null;
    }
    
    public boolean hasUser(String email, String password) {
        for (User user : users) {
            if (user.getEmail().get().equals(email)) {
                String dbPass = user.getPassword().getValue();
                return AuthController.checkPasswordString(password, dbPass);
            }
        }
        return false;
    }

    public boolean deleteProductById(int id) {
        boolean isSuccess = false;
        try {
            synchronized (ConnectDB.class) {
                if (ConnectDB.getConnection() == null) {
                    ConnectDB.initDB();
                }
            }
            String sql = "DELETE FROM products WHERE id = ?";
            PreparedStatement pstmt = ConnectDB.getConnection().prepareStatement(sql);
            pstmt.setInt(1, id);
            if (pstmt.executeUpdate() > 0) {
                System.out.println("Product with ID " + id + " deleted successfully.");
                users.removeIf(p -> p.getId().getValue() == id); // Remove from cache
                isSuccess = true;
            } else {
                System.err.println("Failed to delete product with ID: " + id);
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
            ConnectDB.closeConnection();
        }
        return isSuccess;
    }


    public static UserFactory getInstance() {
        if (instance == null) {
            synchronized (UserFactory.class) {
                if (instance == null) { // Double-checked locking
                    ConnectDB.initDB(); // Ensure DB connection is initialized
                }
            }
            instance = new UserFactory();
        }
        return instance;
    }
}
