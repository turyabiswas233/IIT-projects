package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.controller.admin.DashboardController;
import com.example.utils.UserFactory;

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
        final String password = getPassword();
        try {

            if (UserFactory.getInstance().hasUser(username, password)) {
                String role = UserFactory.getInstance().getUser(username).getRole();
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Login Status");
                alert.setHeaderText("Login Successful");
                alert.setContentText("Email: " + username + "\nRole: " + role + "\n");
                alert.showAndWait();
                if (role.equalsIgnoreCase("super admin"))
                    App.setRoot("admin/dashboardpage", DashboardController.getTitle());
                else if (role.equalsIgnoreCase("user"))
                    App.setRoot("users/dashboardpage", DashboardController.getTitle());
            } else {
                Alert alert = new Alert(Alert.AlertType.ERROR, "", ButtonType.OK);
                alert.setTitle("Login Status");
                alert.setContentText("Error: wrong email or password [" + username + "]");
                alert.setHeaderText("Login Failed");
                alert.showAndWait();
            }
        } catch (Exception e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR, "Error during login: " + e.getMessage(),
                    ButtonType.OK);
            alert.showAndWait();
        }

    }

    private String getUserName() {
        return usernameField.getText();
    }

    private String getPassword() {
        return passwordField.getText();
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        App.setRoot("primarypage", HomeController.getTitle());
    }

    @FXML
    private void onCancelCloseApp() throws IOException {
        App.closeApp();
        System.out.println("Exiting app...");
    }
}