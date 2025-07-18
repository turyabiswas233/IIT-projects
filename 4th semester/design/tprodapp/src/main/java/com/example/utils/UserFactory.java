package com.example.utils;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.example.ConnectDB;
import com.example.controller.AuthController;
import com.example.models.Employee;
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

    public ObservableList<Employee> getEmployees() {
        String query = "SELECT * FROM employees";
        ObservableList<Employee> employees = javafx.collections.FXCollections.observableArrayList();
        try (PreparedStatement statement = ConnectDB.getConnection().prepareStatement(query);
                ResultSet resultSet = statement.executeQuery()) {
            employees.clear();
            while (resultSet.next()) {
                Employee user = new Employee(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getString("email"),
                        resultSet.getString("phone")
                        );
                employees.add(user);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return employees;
    }

    public boolean addUser(User user) {
        String query = "INSERT INTO users (name, email, password, role) VALUES (?, ?, ?, ?)";
        try (PreparedStatement statement = ConnectDB.getConnection().prepareStatement(query)) {
            statement.setString(1, user.getName());
            statement.setString(2, user.getEmail());
            statement.setString(3, user.getPassword());
            statement.setString(4, user.getRole());
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
            if (user.getEmail().equals(email)) {
                return user;
            }
        }
        return null;
    }

    public boolean hasUser(String email, String password) {
        loadUsers();
        for (User user : users) {
            if (user.getEmail().equals(email)) {
                String dbPass = user.getPassword();
                System.out.println(dbPass);
                System.out.println(password);

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
                users.removeIf(p -> p.getId() == id); // Remove from cache
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
