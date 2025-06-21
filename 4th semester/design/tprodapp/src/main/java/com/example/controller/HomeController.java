package com.example.controller;

import com.example.App;
import com.example.ConnectDB;

import javafx.collections.ObservableList;
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
        try {
            AuthController authController = new AuthController();
            authController.setStage(this.stage);

            FXMLLoader fxmlLoader = new FXMLLoader(
                    App.class.getResource("loginview.fxml"));
            fxmlLoader.setController(authController);
            Scene scene = new Scene(fxmlLoader.load());
            stage.setScene(scene);
            stage.close();
            stage.show();

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    private void onGotoDashboardButtonClick() throws IOException {
        try {
            ProductController productController = new ProductController(); 
            productController.setStage(this.stage);
            FXMLLoader fxmlLoader = new FXMLLoader(
                    App.class.getResource("dashboard.fxml"));
            fxmlLoader.setController(productController);
            Scene scene = new Scene(fxmlLoader.load());
            stage.setScene(scene);
            stage.close();
            stage.show();
        } catch (Exception e) {
            System.err.println("Error loading dashboard view: " + e.getMessage());
            e.printStackTrace();
        }
    }
}