package com.example.controller;

import com.example.App;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.*;


public class HomeController  {
    @FXML
    private Label welcomeText;

    @FXML
    private Button loginPageButton;

    @FXML
    private Button signUp;


    public static String getTitle() {
        return "Tb Product Management";
    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        try {
            App.setRoot("loginpage", LoginController.getTitle());

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    protected void onGotoSignupButtonClick() throws IOException {
        try {

            App.setRoot("registrationpage", RegisterController.getTitle());

        } catch (Exception e) {
            System.err.println("Error loading signup view: " + e.getMessage());
            e.printStackTrace();
        }
    }

  
}