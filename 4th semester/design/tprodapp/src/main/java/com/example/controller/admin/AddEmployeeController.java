package com.example.controller.admin;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.paint.Color;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.example.App;
import com.example.ConnectDB;
import com.example.models.User;
import com.example.utils.UserFactory;

public class AddEmployeeController {
    @FXML
    private Button addButton;
    @FXML
    private Button cancelButton;
    @FXML
    private TextField nameField;
    @FXML
    private TextField emailField;
    @FXML
    private TextField phoneField;
    @FXML
    private PasswordField passwordField;
    @FXML
    private Label messageLabel;

    @FXML
    protected void addEmployee() {
        String name = nameField.getText();
        String email = emailField.getText();
        String phone = phoneField.getText();
        String password = passwordField.getText(); // In a real app, hash this password

        if (name.isEmpty() || email.isEmpty() || phone.isEmpty() || password.isEmpty()) {
            messageLabel.setText("All fields are required.");
            return;
        }

        User user = new User(name, email, password, "employee");
        String employeeSql = "INSERT INTO employees(name, email, phone) VALUES(?,?,?)";

        if (UserFactory.getInstance().addUser(user)) {
            try (
                    Connection conn = ConnectDB.getConnection();
                    PreparedStatement pstmtEmployee = conn.prepareStatement(employeeSql)) {

                conn.setAutoCommit(false); // Start transaction

                pstmtEmployee.setString(1, name);
                pstmtEmployee.setString(2, email);
                pstmtEmployee.setString(3, phone);
                pstmtEmployee.executeUpdate();

                conn.commit(); // Commit transaction

                messageLabel.setTextFill(Color.GREEN);
                messageLabel.setText("Employee added successfully!");
                clearFields();

            } catch (SQLException e) {
                messageLabel.setTextFill(Color.RED);
                messageLabel.setText("Error: " + e.getMessage());
                // Consider rolling back transaction in a real app
            }
        }

    }

    @FXML
    protected void goToEmployeePage() throws IOException {
        App.setRoot("admin/employeespage");
    }

    private void clearFields() {
        nameField.clear();
        emailField.clear();
        phoneField.clear();
        passwordField.clear();
    }

    @FXML
    private void initialize() {
        // Hint: initialize() will be called when the associated FXML has been
        // completely loaded.
    }
}