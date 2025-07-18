package com.example.controller.users;

import java.io.IOException;

import com.example.App;
import com.example.models.Order;
import com.example.utils.OrderFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class OrdersController implements Initializable {

    private ObservableList<Order> orderData = FXCollections.observableArrayList();

    @FXML
    private Button productsButton;
    @FXML
    private Button ordersButton;
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

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        loadOrders();
        setupTableView();
    }

    private void setupTableView() {
        ordersTable.setItems(orderData);
    }

    private void loadOrders() {
        orderData.clear();
        orderData.addAll(OrderFactory.loadOrders());
    }

    @FXML
    public void onAddOrderButtonClick() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/example/users/addorderpage.fxml"));
            Parent root = loader.load();
            
            Stage stage = new Stage();
            stage.setTitle("Add New Order");
            stage.setScene(new Scene(root, 600, 500));
            stage.show();
            
            // Refresh orders when the add order window is closed
            stage.setOnHidden(e -> loadOrders());
            
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to open Add Order page: " + e.getMessage());
        }
    }

    @FXML
    public void onProductsButtonClick() {
        try {
            App.setRoot("users/dashboardpage");
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to load Products page: " + e.getMessage());
        }
    }

    @FXML
    public void onOrdersButtonClick() {
        // Already on orders page
    }

    @FXML
    public void onCustomersButtonClick() {
        try {
            App.setRoot("users/customerspage");
        } catch (IOException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Error", "Failed to load Customers page: " + e.getMessage());
        }
    }

    @FXML
    public void onGotoLoginPageButtonClick() {
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
