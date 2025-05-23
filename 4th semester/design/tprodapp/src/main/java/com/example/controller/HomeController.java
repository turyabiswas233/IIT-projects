package com.example.controller;

import com.example.App;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class HomeController {
    private Stage stage;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        AuthController authController = new AuthController();
        authController.setStage(this.stage);

        FXMLLoader fxmlLoader = new FXMLLoader(
                App.class.getResource("loginview.fxml"));
        fxmlLoader.setController(authController);
        Scene scene = new Scene(fxmlLoader.load());
        stage.setScene(scene);
        stage.close();
        stage.show();

    }
}