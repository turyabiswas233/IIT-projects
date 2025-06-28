package com.example.controller;

import java.io.IOException;

import com.example.App; 
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class LoginController implements Controller {
    @FXML
    private Button backButton;

    @FXML
    private TextField usernameField;

    @FXML
    private PasswordField passwordField;

    @FXML
    private Button loginButton;

    @FXML
    private Button cancelButton;

    public static String getTitle() {
        return "Tb Product Management - Login";
    }

    @FXML
    protected void handleLogin() throws IOException {
        final String username = getUserName();
        final String password = AuthController.hashPasswordString(getPassword());

        System.out.println(username + password);

    }

    private String getUserName() {
        return usernameField.getText();
    }

    private String getPassword() {
        return passwordField.getText();
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        App.setRoot("primary", getTitle());
    }

    @FXML
    private void onCancelCloseApp() throws IOException {
        App.closeApp();
        System.out.println("Exiting app...");
    }
}