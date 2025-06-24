package com.example.controller;

import java.io.IOException;

import com.example.PageLoader;

import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class RegisterController implements Controller {

    private Stage stage;

    public Stage setStage(Stage stage) {
        this.stage = stage;
        stage.setTitle(getTitle());

        return stage;
    }

    @Override
    public String getTitle() {
        return "Tb Product Management - Register";
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
    protected void handleSignup() {
        System.out.println("Signup button clicked");
    }

    @FXML
    protected void onCancelCloseApp() {
        stage.close();
        System.out.println("Exiting app...");
    }
}
