package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.controller.admin.DashboardController;
import com.example.utils.Session;
import com.example.utils.UserFactory;

import javafx.fxml.FXML;
import javafx.scene.control.*;

public class LoginController {
    @FXML
    private Button loginButtonAdmin;
    @FXML
    private Button loginButtonEmployee;
    @FXML
    private Button cancelButton;

    @FXML
    private TextField usernameField;
    @FXML
    private PasswordField passwordField;

    public static String getTitle() {
        return "Tb Product Management - Login";
    }

    @FXML
    protected void handleLoginAsAdmin() throws IOException {
        login("super_admin");
    }

    @FXML
    protected void handleLoginAsEmployee() throws IOException {
        login("employee");
    }

    private void login(String roleType) {
        final String username = getUserName();
        final String password = getPassword();
        try {

            if (UserFactory.getInstance().hasUser(username, password)) {
                String role = UserFactory.getInstance().getUser(username).getRole();
                Session.setRole(role);

                Alert alert = new Alert(Alert.AlertType.INFORMATION);

                if (role.equalsIgnoreCase(roleType) && roleType.equals("employee")) {
                    App.setRoot("users/dashboardpage", DashboardController.getTitle());
                } else if (role.equalsIgnoreCase("super_admin") && roleType.equals("super_admin")) {
                    App.setRoot("admin/dashboardpage", DashboardController.getTitle());
                } else {
                    alert = new Alert(Alert.AlertType.ERROR, "", ButtonType.OK);
                    alert.setTitle("Login Status");
                    alert.setContentText("Error: wrong email or password [" + username + "]");
                    alert.setHeaderText("Login Failed");
                    alert.showAndWait();
                }
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

    @FXML
    private void initialize() {
        btnHoverBlack(loginButtonAdmin, "#0dc453");
        btnHoverBlack(loginButtonEmployee, "#2591cf");
        btnHoverBlack(cancelButton, "#d85656");
    }

    private void btnHoverBlack(Button t, String color) {
        String oldStyle = t.getStyle();

        t.setOnMouseEntered(e -> {
            t.setStyle("-fx-background-color: " + color + "; -fx-border-color: #444; -fx-border-width: 1; -fx-border-radius: 50; -fx-background-radius: 50;");

        });
        t.setOnMouseExited(e -> {
            t.setStyle(oldStyle);
        });

    }
}