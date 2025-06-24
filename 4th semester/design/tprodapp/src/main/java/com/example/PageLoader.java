package com.example;

import java.io.IOException;

import com.example.controller.Controller;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;

public class PageLoader {

    public static Parent loadFXML(String fxml, Controller c) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        fxmlLoader.setController(c);
        return fxmlLoader.load();
    }
}
