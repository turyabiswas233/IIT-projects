package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.controller.users.DashboardController;
import com.example.models.InvoiceItem;
import com.example.models.Order;
import com.example.utils.OrderFactory;
import com.example.utils.Session;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;

public class OrdersController {

    private ObservableList<Order> orderData = FXCollections.observableArrayList();

    @FXML
    private Button productsButton;
    @FXML
    private Button customersButton;
    @FXML
    private Button logoutButton;
    @FXML
    private Button addOrderButton;
    @FXML
    private Button searchButton;
    @FXML
    private TextField searchField;
    @FXML
    private TableView<Order> ordersTable;
    @FXML
    private TableColumn<Order, Integer> orderIdColumn;
    @FXML
    private TableColumn<Order, String> customerNameColumn;
    @FXML
    private TableColumn<Order, String> productNameColumn;
    @FXML
    private TableColumn<Order, Integer> quantityColumn;
    @FXML
    private TableColumn<Order, Double> totalPriceColumn;
    @FXML
    private TableColumn<Order, String> orderDateColumn;

    private Order selectedOrder;

    @FXML
    private void initialize() {
        loadOrders();
        ordersTable.setItems(orderData);

        // Listen for selection changes
        ordersTable.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
            selectedOrder = newSelection;
            if (selectedOrder != null) {
                System.out.println("Selected Order: " + selectedOrder.getId());
            }
        });

        if (!Session.getRole().equalsIgnoreCase("employee")) {
            addOrderButton.setVisible(false);
        }

    }

    private void loadOrders() {
        orderData.setAll(OrderFactory.getInstance().loadOrders());
    }

    @FXML
    protected void onAddOrderButtonClick() {
        try {
            if (Session.getRole().equalsIgnoreCase("employee"))
                App.setRoot("users/addorderpage", "Add New Order");
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to open Add Order page: " + e.getMessage());
        }
    }

    @FXML
    protected void onProductsButtonClick() {
        try {
            switch (Session.getRole().toLowerCase()) {
                case "employee":
                    App.setRoot("users/dashboardpage", DashboardController.getTitle());
                    break;

                case "super_admin":
                    App.setRoot("admin/dashboardpage", com.example.controller.admin.DashboardController.getTitle());
                    break;
                default:
                    break;
            }

        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to load Products page: " + e.getMessage());
        }
    }

    @FXML
    protected void onClickShowUsers() {
        try {
            App.setRoot("users/employeespage");
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to load Customers page: " + e.getMessage());
        }
    }

    @FXML
    protected void onClickSeeInvoicePage() {
        if (selectedOrder == null) {
            showAlert(AlertType.WARNING, "No Selection", "Please select an order to view the invoice.");
            return;
        }
        try {
            FXMLLoader loader = new FXMLLoader(App.class.getResource("invoicepage.fxml"));

            InvoiceController invoiceController = new InvoiceController();
            // You may need to convert Order to InvoiceItem(s) as needed
            ObservableList<InvoiceItem> items = FXCollections.observableArrayList();
            items.add(new InvoiceItem(
                    selectedOrder.getProductName(),
                    selectedOrder.getQuantity(),
                    selectedOrder.getTotalPrice() / selectedOrder.getQuantity(),
                    selectedOrder.getTotalPrice()));
            invoiceController.setInvoiceData(
                    String.valueOf(selectedOrder.getId()),
                    selectedOrder.getCustomerName(),
                    "",
                    items);

            loader.setController(invoiceController);

            // App.setRoot("invoicepage", "Invoice Page - ADMIN");
            App.setRoot("Invoice Page - ADMIN", loader);

        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to show invoice: " + e.getMessage());
        }
    }

    @FXML
    protected void onGotoLoginPageButtonClick() {
        try {
            App.setRoot("loginpage");
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to logout: " + e.getMessage());
        }
    }

    private void showAlert(AlertType alertType, String title, String message) {
        Alert alert = new Alert(alertType);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
