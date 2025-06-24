package com.example;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import com.example.controller.HomeController;

public class App extends Application {
    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {

        HomeController homeController = new HomeController();
        homeController.setStage(stage);
        scene = new Scene(PageLoader.loadFXML("primary", homeController));
        
        stage.setTitle(homeController.getTitle());
        stage.setScene(scene);
        stage.setWidth(1000);
        stage.setHeight(800);
        stage.setResizable(false);

        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}
