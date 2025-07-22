package com.example.controller.users;

import java.text.DecimalFormat;

import com.example.App;
import com.example.controller.Controller;
import com.example.models.Customer;
import com.example.models.Product;
import com.example.utils.OrderFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import javafx.util.StringConverter;

public class AddOrderController implements Controller {

    @FXML
    private ComboBox<Customer> customerComboBox;
    @FXML
    private ComboBox<Product> productComboBox;
    @FXML
    private Spinner<Integer> quantitySpinner;
    @FXML
    private TextField unitPriceField;
    @FXML
    private TextField totalPriceField;
    @FXML
    private Button createOrderButton;
    @FXML
    private Button cancelButton;

    private ObservableList<Customer> customers = FXCollections.observableArrayList();
    private ObservableList<Product> products = FXCollections.observableArrayList();
    private DecimalFormat priceFormat = new DecimalFormat("#0.00");

    @FXML
    private void initialize() {
        setupSpinner();
        loadData();
        setupComboBoxes();
        setupEventHandlers();
    }

    private void setupSpinner() {
        SpinnerValueFactory<Integer> valueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(1, 1000, 1);
        quantitySpinner.setValueFactory(valueFactory);
        quantitySpinner.valueProperty().addListener((obs, oldValue, newValue) -> updateTotalPrice());
    }

    private void loadData() {
        customers.clear();
        products.clear();
        customers.addAll(OrderFactory.loadCustomersWithPhone());
        products.addAll(OrderFactory.loadAvailableProducts());
    }

    private void setupComboBoxes() {
        // Setup customer combo box
        customerComboBox.setItems(customers);
        customerComboBox.setConverter(new StringConverter<Customer>() {
            @Override
            public String toString(Customer customer) {
                return customer != null ? customer.getName() + " (" + customer.getPhone() + ")" : "";
            }

            @Override
            public Customer fromString(String string) {
                return null;
            }
        });

        // Setup product combo box
        productComboBox.setItems(products);
        productComboBox.setConverter(new StringConverter<Product>() {
            @Override
            public String toString(Product product) {
                return product != null
                        ? product.getName() + " - $" + priceFormat.format(product.getPrice()) + " (Available: "
                                + product.getQuantity() + ")"
                        : "";
            }

            @Override
            public Product fromString(String string) {
                return null;
            }
        });

        productComboBox.valueProperty().addListener((obs, oldValue, newValue) -> {
            if (newValue != null) {
                unitPriceField.setText("$" + priceFormat.format(newValue.getPrice()));

                // Update spinner max value based on available quantity
                SpinnerValueFactory<Integer> valueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(
                        1, newValue.getQuantity(), 1);
                quantitySpinner.setValueFactory(valueFactory);

                updateTotalPrice();
            } else {
                unitPriceField.clear();
                totalPriceField.clear();
            }
        });
    }

    private void setupEventHandlers() {
        // Additional event handlers can be added here if needed
    }

    private void updateTotalPrice() {
        Product selectedProduct = productComboBox.getValue();
        if (selectedProduct != null && quantitySpinner.getValue() != null) {
            double total = selectedProduct.getPrice() * quantitySpinner.getValue();
            totalPriceField.setText("$" + priceFormat.format(total));
        }
    }

    @FXML
    public void onCreateOrderButtonClick() {
        Customer selectedCustomer = customerComboBox.getValue();
        Product selectedProduct = productComboBox.getValue();
        Integer quantity = quantitySpinner.getValue();

        if (selectedCustomer == null) {
            showAlert(AlertType.WARNING, "Validation Error", "Please select a customer.");
            return;
        }

        if (selectedProduct == null) {
            showAlert(AlertType.WARNING, "Validation Error", "Please select a product.");
            return;
        }

        if (quantity == null || quantity <= 0) {
            showAlert(AlertType.WARNING, "Validation Error", "Please enter a valid quantity.");
            return;
        }

        if (quantity > selectedProduct.getQuantity()) {
            showAlert(AlertType.WARNING, "Validation Error",
                    "Quantity cannot exceed available stock (" + selectedProduct.getQuantity() + ").");
            return;
        }

        // Create the order
        boolean success = OrderFactory.createOrder(selectedCustomer, selectedProduct, quantity);

        if (success) {
            showAlert(AlertType.INFORMATION, "Success", "Order created successfully!");
            closeWindow();
        } else {
            showAlert(AlertType.ERROR, "Error", "Failed to create order. Please try again.");
        }
    }

    @FXML
    public void onCancelButtonClick() {
        closeWindow();
    }

    private void closeWindow() {
        try {
            App.setRoot("users/orderspage");
        } catch (Exception e) {
            System.out.println("failed to load orders page: " + e.getMessage());
            e.printStackTrace();
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
