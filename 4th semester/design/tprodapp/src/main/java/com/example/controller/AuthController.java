package com.example.controller;

import com.example.App;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class AuthController {
    private Stage stage;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @FXML
    protected void login() throws IOException {
        System.out.println("login");
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        HomeController homeController = new HomeController();
        homeController.setStage(this.stage);

        FXMLLoader fxmlLoader = new FXMLLoader(
                App.class.getResource("primary.fxml"));
        fxmlLoader.setController(homeController);
        Scene scene = new Scene(fxmlLoader.load());
        stage.setScene(scene);
        stage.close();
        stage.show();
    }

    @FXML
    protected void onCancelCloseApp()  throws IOException {
        stage.close();
        System.out.println("Exiting app...");
    }
}