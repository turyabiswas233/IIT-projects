package com.example.controller;

import com.example.App;
import com.example.controller.users.DashboardController;
import com.example.models.Customer;
import com.example.utils.CustomerFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class CustomerController {
    private ObservableList<Customer> customerData = FXCollections.observableArrayList();

    @FXML
    private TableView<Customer> customerTable;

    @FXML
    private TableColumn<Customer, Integer> idColumn;

    @FXML
    private TableColumn<Customer, String> nameColumn;

    @FXML
    private TableColumn<Customer, String> phoneColumn;

    @FXML
    private TextField searchField;

    @FXML
    private Button productsButton;

    @FXML
    private Button ordersButton;

    @FXML
    private Button customersButton;

    @FXML
    private Button logoutButton;

    @FXML
    private void initialize() {
        customerData.clear();
        customerData.addAll(CustomerFactory.loadCustomers());

        customerTable.setItems(customerData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });

        // logout page
        logoutButton.setOnAction(e -> {
            try {

                App.setRoot("loginpage");

            } catch (Exception err) {
                System.err.println("Error loading login view: " + err.getMessage());
                err.printStackTrace();
            }
        });

         productsButton.setOnAction(e -> {
            try {
                App.setRoot("users/dashboardpage", DashboardController.getTitle());
            } catch (Exception err) {
                System.err.println(err.getLocalizedMessage());
                err.printStackTrace();
            }
        });
    }

    private void filterProductList(String searchText) {
        ObservableList<Customer> filteredList = FXCollections.observableArrayList();
        for (Customer u : customerData) {
            if (u.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(u.getId()).contains(searchText)
                    || u.getPhone().toLowerCase().contains(searchText.toLowerCase())) {
                filteredList.add(u);
            }
        }
        customerTable.setItems(filteredList);
    }

}
