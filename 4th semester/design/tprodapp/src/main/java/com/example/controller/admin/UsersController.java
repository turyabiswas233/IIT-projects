package com.example.controller.admin;

import java.io.IOException;

import com.example.App; 
import com.example.models.Employee;
import com.example.utils.UserFactory;

import javafx.fxml.FXML;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.*;

public class UsersController  {

    @FXML
    private Button addEmployeeButton;

    private ObservableList<Employee> usersData = FXCollections.observableArrayList();

    @FXML
    private Button ordersButton;
    @FXML
    private Button productsButton;
    @FXML
    private Button logoutButton;
    @FXML
    private TableColumn<Employee, Integer> idColumn;
    @FXML
    private TableColumn<Employee, String> nameColumn;
    @FXML
    private TableColumn<Employee, String> emailColumn;
    @FXML
    private TableColumn<Employee, String> phoneColumn;
    @FXML
    private TableView<Employee> productTable;
    @FXML
    private TextField searchField;

    public static String getTitle() {
        return "Tb Product Management - Admin";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)

        usersData.addAll(UserFactory.getInstance().getEmployees());

        productTable.setItems(usersData);

        // Add listeners for search, add, edit, delete buttons
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            filterProductList(newValue);
        });

        // set an event on click an item from the table
        productTable.setOnMouseClicked(event -> {
            if (event.getClickCount() > 0) {
                Employee selectedProduct = productTable.getSelectionModel().getSelectedItem();
                if (selectedProduct != null) {
                    System.out.println(
                            "Selected Product: " + selectedProduct.getName() + ", Email: "
                                    + selectedProduct.getEmail());
                }
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
    protected void onGotoDashboardButtonClick() {
        try {
            App.setRoot("admin/dashboardpage", DashboardController.getTitle());
        } catch (Exception err) {
            System.err.println(err.getLocalizedMessage());
            err.printStackTrace();
        }
    }

    @FXML
    protected void onGotoOrderPageButtonClick()  {
        try {
            App.setRoot("admin/orderspage");
        } catch (Exception err) {
            System.out.println("failed to load orders page" + err.getMessage());
            err.printStackTrace();
        }
    }

    @FXML
    protected void onClickShowUsers() throws IOException {
        try {
            App.setRoot("admin/employeespage", getTitle());
        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @FXML
    protected void onGotoAddEmployeeButtonClick() {
            try {
                App.setRoot("admin/addemployeepage");

            } catch (Exception err) {
                System.out.println("failed to load page" + err.getLocalizedMessage());
                err.printStackTrace();
            }
        }

    private void filterProductList(String searchText) {
        ObservableList<Employee> filteredList = FXCollections.observableArrayList();
        for (Employee u : usersData) {
            if (u.getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    String.valueOf(u.getId()).contains(searchText)
                    || u.getEmail().toLowerCase().contains(searchText.toLowerCase())) {
                filteredList.add(u);
            }
        }
        productTable.setItems(filteredList);
    }

}
