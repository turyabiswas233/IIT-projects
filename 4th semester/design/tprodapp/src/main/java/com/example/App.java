package com.example;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

import com.example.controller.HomeController;

public class App extends Application {
    private static Scene scene;
    private static Stage stage;

    @Override
    public void start(Stage stage) throws IOException {
        App.stage = stage;
        scene = new Scene(loadFXML("loginpage"));
        stage.setTitle(HomeController.getTitle());
        stage.setScene(scene);
        stage.setWidth(850);
        stage.setHeight(650);
        stage.setResizable(false);
        stage.show();
    }

    @FXML
    public static void setRoot(String fxml) throws IOException {
        App.scene.setRoot(loadFXML(fxml));
        App.stage.show();
    }

    @FXML
    public static void setRoot(String title, FXMLLoader p) throws IOException {
        App.scene.setRoot(p.load());
        App.stage.setTitle(title);
        App.stage.show();
    }

    @FXML
    public static void setRoot(String fxml, String title) throws IOException {
        App.scene.setRoot(loadFXML(fxml));
        App.stage.setTitle(title);
        App.stage.show();
    }

    @FXML
    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void closeApp() {
        System.out.println("Exiting app...");
        App.stage.close();
    }

    public static void main(String[] args) {
        launch();
    }

}
