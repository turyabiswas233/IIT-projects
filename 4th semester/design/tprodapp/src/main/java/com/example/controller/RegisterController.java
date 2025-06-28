package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.models.User;
import com.example.utils.UserFactory;

import javafx.fxml.FXML;
import javafx.scene.control.*;

public class RegisterController implements Controller {
    @FXML
    private Button backButton;

    @FXML
    private TextField fullNameField;

    @FXML
    private TextField emailField;

    @FXML
    private PasswordField passwordField;

    @FXML
    private ComboBox<String> adminTypeComboBox;

    @FXML
    private Button signupButton;

    @FXML
    private Button cancelButton;

    public static String getTitle() {
        return "Tb Product Management - Register";
    }

    @FXML
    private void initialize() {
        // Initialize the admin type combo box with options
        adminTypeComboBox.getItems().clear();
        adminTypeComboBox.getItems().addAll("Super Admin", "Admin", "User");
        adminTypeComboBox.getSelectionModel().selectFirst(); // Default selection
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        App.setRoot("primary", LoginController.getTitle());
    }

    @FXML
    protected void handleSignup() {
        signupButton.setDisable(true);
        signupButton.setText("Signing Up...");
        try {
            User user = new User(
                    fullNameField.getText(),
                    emailField.getText(),
                    AuthController.hashPasswordString(passwordField.getText()),
                    adminTypeComboBox.getValue());
            UserFactory.getInstance().addUser(user);
        } catch (Exception e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR, "Error during registration: " + e.getMessage(),
                    ButtonType.OK);
            alert.showAndWait();
        } finally {
            signupButton.setDisable(false);
            signupButton.setText("Sign Up");
        }
    }

    @FXML
    protected void onCancelCloseApp() {
        System.out.println("Exiting app...");
        App.closeApp();
    }
}
