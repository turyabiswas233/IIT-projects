package com.example.controller;

import java.io.IOException;

import com.example.ConnectDB;
import com.example.PageLoader;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class DashboardController implements Controller {
    private Stage stage;
    private ConnectDB connectDB;
    private ObservableList<Product> productData = FXCollections.observableArrayList();

    @FXML
    private TableView<Product> productTable;
    @FXML
    private TextField searchField;
    @FXML
    private Button editProductButton;
    @FXML
    private Button deleteProductButton;

    public Stage setStage(Stage stage) {
        this.stage = stage;
        stage.setTitle(getTitle());
        return stage;
    }

    @Override
    public String getTitle() {
        return "Tb Product Management - Dashboard";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)
        connectDB = new ConnectDB();
        connectDB.initDB();
        productData.addAll(connectDB.getProducts());
        productTable.setItems(productData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });
    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        try {
            LoginController loginController = new LoginController();
            loginController.setStage(this.stage);

            Scene scene = new Scene(PageLoader.loadFXML("loginview", loginController));
            stage.setScene(scene);
            stage.close();
            stage.show();

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    protected void onGotoAddProductButtonClick() throws IOException {
        try {
            ProductController productController = new ProductController();
            stage = productController.setStage(this.stage);
            Scene scene = new Scene(PageLoader.loadFXML("addproduct", productController));
            stage.setScene(scene);
            stage.close();
            stage.show();

        } catch (Exception e) {
            System.err.println("Error loading add product view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void filterProductList(String searchText) {
        ObservableList<Product> filteredList = FXCollections.observableArrayList();
        for (Product p : productData) {
            if (p.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(p.getId()).contains(searchText)
                    || p.getCategory().toLowerCase().contains(searchText.toLowerCase())) { // Example: search by name or
                                                                                           // ID or Category
                filteredList.add(p);
            }
        }
        productTable.setItems(filteredList);
    }

}
