package com.example.controller.admin;

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
import javafx.scene.control.Alert.AlertType;

public class DashboardController implements Controller {
    private ObservableList<Product> productData = FXCollections.observableArrayList();
    private ProductFactory productFactory = new ProductFactory();

    @FXML
    private Button ordersButton;
    @FXML
    private Button usersButton;
    @FXML
    private Button productsButton;
    @FXML
    private Button logoutButton;
    @FXML
    private Button addProductButtonPage;
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
    @FXML
    private Button editProductButton;
    @FXML
    private Button deleteProductButton;

    public static String getTitle() {
        return "Tb Product Management - Dashboard";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)

        productData.addAll(productFactory.getProducts( ));
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

        productsButton.setOnAction(e -> {
            try {
                App.setRoot("admin/dashboardpage", DashboardController.getTitle());
            } catch (Exception err) {
                System.err.println(err.getLocalizedMessage());
                err.printStackTrace();
            }
        });

        // make event for deleting a product
        deleteProductButton.setOnAction(e -> {
            if (productFactory.deleteProductById(productTable.getSelectionModel().getSelectedItem().getId())) {
                System.out.println("Product deleted successfully.");
                productData.setAll(productFactory.getProducts());
            } else {
                System.err.println("Failed to delete product.");
            }
        });
        ordersButton.setOnMouseClicked(e -> {
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setContentText("Page not found");
            alert.showAndWait();
            // try {
            // App.setRoot("orderspage");

            // } catch (Exception err) {
            // err.printStackTrace();
            // }
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

    @FXML
    protected void onClickShowUsers() throws IOException {
        try {

            App.setRoot("admin/employeespage", UsersController.getTitle());

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

     @FXML
    protected void onClickShowCustomers() throws IOException {
        try {
            App.setRoot("customerspage", "Tb Product Management - Customers");
        } catch (Exception e) {
            System.err.println("Error loading customers view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    protected void onGotoAddProductButtonClick() throws IOException {
        try {

            App.setRoot("admin/addproductpage");

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
                    || p.getCategory().toLowerCase().contains(searchText.toLowerCase())) {
                filteredList.add(p);
            }
        }
        productTable.setItems(filteredList);
    }

}
