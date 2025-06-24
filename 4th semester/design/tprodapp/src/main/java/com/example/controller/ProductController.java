package com.example.controller;

import java.io.IOException;

import com.example.ConnectDB;
import com.example.PageLoader;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class ProductController implements Controller {
    private Stage stage;
    private ConnectDB connectDB;
    private ObservableList<Product> productData = FXCollections.observableArrayList();

    @FXML
    private TextField productNameField;
    @FXML
    private TextField productIdField;
    @FXML
    private TextField productCategoryField;
    @FXML
    private TextField productPriceField;
    @FXML
    private TextField productQuantityField;

    public Stage setStage(Stage stage) {
        this.stage = stage;
        stage.setTitle(getTitle());
        return stage;
    }

    @Override
    public String getTitle() {
        return "Tb Product Management - Add Product";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)
        connectDB = new ConnectDB();
        connectDB.initDB();
        productData.addAll(connectDB.getProducts());
    }

    @FXML
    protected String getText(TextField tf) {
        return tf.getText();
    }

    @FXML
    protected int getNumber(TextField tf) {
        try {
            return Integer.parseInt(tf.getText());
        } catch (NumberFormatException e) {
            System.err.println("Invalid number format: " + tf.getText());
            return 0; // Default to 0 if invalid
        }
    }

    @FXML
    protected void onHandleProductAddClick() {
        // You can open a new window or dialog to add product details
        System.out.println("Add Product window opened successfully.");

        Product newProduct = new Product(getText(productNameField),
                getText(productCategoryField),
                Double.parseDouble(getText(productPriceField)), Integer.parseInt(getText(productQuantityField)));

        connectDB.uploadProduct(newProduct);
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        try {
            HomeController homeController = new HomeController();
            homeController.setStage(this.stage);

            Scene scene = new Scene(PageLoader.loadFXML("primary", homeController));
            stage.setScene(scene);
            stage.close();
            stage.show();

        } catch (Exception e) {
            System.err.println("Error loading home view: " + e.getMessage());
            e.printStackTrace();
        }
    }

}
