package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.ConnectDB;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class ProductController {
    private Stage stage;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @FXML
    private TableView<Product> productTable;
    @FXML
    private TextField searchField;
    @FXML
    private Button addProductButton;
    @FXML
    private Button editProductButton;
    @FXML
    private Button deleteProductButton;

    private ObservableList<Product> productData = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)
        ConnectDB connectDB = new ConnectDB();
        productData.addAll(connectDB.initDB());

        productTable.setItems(productData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });

        // Example for add product button
        // addProductButton.setOnAction(event -> handleAddProduct());
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

    private void filterProductList(String searchText) {
        // Implement search logic here
        // Filter productData and update productTable.setItems()
        ObservableList<Product> filteredList = FXCollections.observableArrayList();
        for (Product p : productData) {
            if (p.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(p.getId()).contains(searchText)) { // Example: search by name or ID
                filteredList.add(p);
            }
        }
        productTable.setItems(filteredList);
    }

}
