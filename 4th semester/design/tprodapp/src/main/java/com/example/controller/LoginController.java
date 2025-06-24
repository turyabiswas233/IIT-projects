package com.example.controller;

import com.example.PageLoader;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import org.mindrot.jbcrypt.BCrypt;
import java.io.IOException;

public class LoginController implements Controller {
    private Stage stage;
    @FXML private TextField usernameField = new TextField();
    @FXML private PasswordField passwordField = new PasswordField();

    public Stage setStage(Stage stage) {
        this.stage = stage;
        stage.setTitle(getTitle());

        return stage;
    }

    @Override
    public String getTitle() {
        return "Tb Product Management - Login";
    }

    @FXML
    protected void handleLogin() throws IOException {
        System.out.println(getUserName());
        System.out.println(hashPassString(getPassword()));
         
    }

    private  String hashPassString(String password) {
        // Use a fixed salt so the same password always produces the same hash
        String fixedSalt = BCrypt.gensalt();
        return BCrypt.hashpw(password, fixedSalt);
    }

    private String getUserName() {
        return usernameField.getText();
    }

    private String getPassword() {
        return passwordField.getText();
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        HomeController homeController = new HomeController();
        homeController.setStage(this.stage);

        Scene scene = new Scene(PageLoader.loadFXML("primary", homeController));
        stage.setScene(scene);
        stage.close();
        stage.show();
    }

    @FXML
    private void onCancelCloseApp() throws IOException {
        stage.close();
        System.out.println("Exiting app...");
    }
}