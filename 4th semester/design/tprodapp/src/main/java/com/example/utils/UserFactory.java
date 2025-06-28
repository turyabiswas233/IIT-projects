package com.example.utils;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.example.ConnectDB;
import com.example.models.User;

import javafx.collections.ObservableList;

public class UserFactory {
    private static UserFactory instance = null;
    private static ObservableList<User> users = javafx.collections.FXCollections.observableArrayList();
    private UserFactory() {
        // Private constructor to prevent instantiation
        loadUsers();
    }
    public ObservableList<User> getUsers() {
        return users;
    }

    public void loadUsers() {
        String query = "SELECT * FROM users";
        try (PreparedStatement statement = ConnectDB.getConnection().prepareStatement(query);
                ResultSet resultSet = statement.executeQuery()) {
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

    public User getUser(String email, String password) {
        for (User user : users) {
            if (user.getEmail().get().equals(email) && user.getPassword().get().equals(password)) {
                return user;
            }
        }
        return null;
    }

}
