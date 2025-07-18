package com.example.controller.users;

import java.io.IOException;

import com.example.App;
import com.example.controller.Controller;
import com.example.controller.LoginController;
import com.example.models.Product;
import com.example.utils.ProductFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class DashboardController implements Controller {

    private ObservableList<Product> productData = FXCollections.observableArrayList();
    private ProductFactory productFactory = new ProductFactory();

    @FXML
    private Button productsButton;
    @FXML
    private Button ordersButton;
    @FXML
    private Button customersButton;
    @FXML
    private Button logoutButton;
    @FXML
    private TableColumn<Product, Integer> idColumn;
    @FXML
    private TableColumn<Product, String> nameColumn;
    @FXML
    private TableColumn<Product, String> categoryColumn;
    @FXML
    private TableColumn<Product, Double> priceColumn;
    @FXML
    private TableColumn<Product, Integer> quantityColumn;
    @FXML
    private TableView<Product> productTable;
    @FXML
    private TextField searchField;

    public static String getTitle() {
        return "Tb Product Management - Dashboard";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)

        productData.addAll(productFactory.getProducts());
        productTable.setItems(productData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });

        // set an event on click an item from the table
        productTable.setOnMouseClicked(event -> {
            if (event.getClickCount() > 0) {
                Product selectedProduct = productTable.getSelectionModel().getSelectedItem();
                if (selectedProduct != null) {
                    System.out.println(
                            "Selected Product: " + selectedProduct.getName() + ", ID: " + selectedProduct.getId());
                }
            }
        });

        ordersButton.setOnMouseClicked(e -> {
            try {
                App.setRoot("users/orderspage");
            } catch (Exception err) {
                System.out.println("failed to load orders page" + err.getMessage());
                err.printStackTrace();
            }
        });

        customersButton.setOnMouseClicked(e -> {
            try {
                App.setRoot("users/customerspage");

            } catch (Exception err) {
                System.out.println("failed to load customers page" + err.getMessage());
                err.printStackTrace();
            }
        });

    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        try {
            App.setRoot("loginpage", LoginController.getTitle());
        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void filterProductList(String searchText) {
        ObservableList<Product> filteredList = FXCollections.observableArrayList();
        for (Product p : productData) {
            if (p.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(p.getId()).contains(searchText)
                    || p.getCategory().toLowerCase().contains(searchText.toLowerCase())) {
                filteredList.add(p);
            }
        }
        productTable.setItems(filteredList);
    }

}
