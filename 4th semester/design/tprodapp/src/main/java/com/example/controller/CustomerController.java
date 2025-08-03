package com.example.controller;

import com.example.App;
import com.example.controller.users.DashboardController;
import com.example.models.Customer;
import com.example.utils.CustomerFactory;
import com.example.utils.Session;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class CustomerController  {
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
        customerTable.setItems(CustomerFactory.loadCustomers());

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

    @FXML
    public void onGotoOrderPageButtonClick() {
        try {
            switch (Session.getRole().toLowerCase()) {
                case "employee":
                    App.setRoot("users/orderspage", DashboardController.getTitle());
                    break;

                case "super_admin":
                    App.setRoot("admin/orderspage", com.example.controller.admin.DashboardController.getTitle());
                    break;
                default:
                    break;
            }
        } catch (Exception err) {
            System.err.println(err.getLocalizedMessage());
            err.printStackTrace();
        }
    }

    public static String getTitle() {
        return "Tb Product Management - Customer List";

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
