package com.example.controller.admin;

import java.io.IOException;

import com.example.App;
import com.example.controller.Controller;
import com.example.models.User;
import com.example.utils.UserFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class UsersController implements Controller {
    private ObservableList<User> usersData = FXCollections.observableArrayList();

    @FXML
    private Button ordersButton;
    @FXML
    private Button usersButton;
    @FXML
    private Button productsButton;
    @FXML
    private Button categoriesButton;
    @FXML
    private Button logoutButton;
    @FXML
    private TableColumn<User, Integer> idColumn;
    @FXML
    private TableColumn<User, String> nameColumn;
    @FXML
    private TableColumn<User, String> emailColumn;
    @FXML
    private TableColumn<User, String> roleColumn;
    @FXML
    private TableView<User> productTable;
    @FXML
    private TextField searchField;
    @FXML
    private Button editUserButton;
    @FXML
    private Button deleteUserButton;

    public static String getTitle() {
        return "Tb User Management - Dashboard";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)

        usersData.addAll(UserFactory.getInstance().getUsers());
        productTable.setItems(usersData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });

        // set an event on click an item from the table
        productTable.setOnMouseClicked(event -> {
            if (event.getClickCount() > 0) {
                User selectedProduct = productTable.getSelectionModel().getSelectedItem();
                if (selectedProduct != null) {
                    System.out.println(
                            "Selected Product: " + selectedProduct.getName() + ", Email: "
                                    + selectedProduct.getEmail());
                }
            }
        });

        // make event for routing
        productsButton.setOnAction(e -> {
            try {
                App.setRoot("admin/dashboardpage", DashboardController.getTitle());
            } catch (Exception err) {
                System.err.println(err.getLocalizedMessage());
                err.printStackTrace();
            }
        });
        // make event for deleting a product
        deleteUserButton.setOnAction(e -> {
            if (UserFactory.getInstance()
                    .deleteProductById(productTable.getSelectionModel().getSelectedItem().getId())) {
                System.out.println("Product deleted successfully.");
                usersData.setAll(UserFactory.getInstance().getUsers());
            } else {
                System.err.println("Failed to delete product.");
            }
        });
    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        try {

            App.setRoot("loginpage");

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    protected void onClickShowUsers() throws IOException {
        try {
            App.setRoot("admin/userspage", getTitle());
        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void filterProductList(String searchText) {
        ObservableList<User> filteredList = FXCollections.observableArrayList();
        for (User u : usersData) {
            if (u.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(u.getId()).contains(searchText)
                    || u.getEmail().toLowerCase().contains(searchText.toLowerCase())) {
                filteredList.add(u);
            }
        }
        productTable.setItems(filteredList);
    }

}
