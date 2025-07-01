package com.example.controller;

import java.io.IOException;

import com.example.App;
import com.example.ConnectDB;
import com.example.models.Product;
import com.example.utils.ProductFactory;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class ProductController implements Controller {

    private ProductFactory productFactory = new ProductFactory();

    final ConnectDB db = new ConnectDB();
     
    @FXML
    private Button addProductButton;

    @FXML
    private Button backHome;

    private ObservableList<Product> productData = FXCollections.observableArrayList();

    @FXML
    private TextField productNameField;
    @FXML
    private TextField productIdField;
    @FXML
    private ComboBox<String> productCategoryField;
    @FXML
    private TextField productPriceField;
    @FXML
    private TextField productQuantityField;

    public static String getTitle() {
        return "Tb Product Management - Add Product";
    }

    @FXML
    public void initialize() {
        // Load some dummy data (you'd replace this with database interaction)
        productData.addAll(productFactory.getProducts());
        productData.sort((p1, p2) -> p1.getName().compareToIgnoreCase(p2.getName()));

        productData.forEach(e -> {
            productCategoryField.getItems().add(e.getCategory());
        });
        productCategoryField.getItems().add("Other");
        productCategoryField.getSelectionModel().selectFirst();
        productIdField.setText(String.valueOf(productFactory.getNextProductId()));
    }

    protected <T> String getText(T tf) {
        if (tf instanceof TextField) {
            return ((TextField) tf).getText();
        }
        else if(tf instanceof ComboBox){
            return ((ComboBox<?>) tf).getSelectionModel().getSelectedItem().toString();
        }
        return null;
    }

    @FXML
    protected int getNumber(TextField tf) {
        try {
            return Integer.parseInt(tf.getText());
        } catch (NumberFormatException e) {
            System.err.println("Invalid number format: " + tf.getText());
            return 0; // Default to 0 if invalid
        }
    }

    @FXML
    protected void onHandleProductAddClick() {
        addProductButton.setDisable(true);
        addProductButton.setText("Please wait...");
        // You can open a new window or dialog to add product details
        System.out.println("Add Product window opened successfully.");

        Product newProduct = new Product(getText(productNameField),
                getText(productCategoryField),
                Double.parseDouble(getText(productPriceField)), Integer.parseInt(getText(productQuantityField)));

        try {
            if (productFactory.uploadProduct(newProduct)) {
                System.out.println("Product added successfully.");
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Success");
                alert.setHeaderText("Product Added Successfully");
                alert.setContentText("Product " + newProduct.getName() + " has been added successfully.");
                alert.showAndWait();
                App.setRoot("dashboardpage", DashboardController.getTitle());
            }

        } catch (Exception e) {
            System.err.println("Error adding product: " + e.getMessage());
            e.printStackTrace();
        } finally {
            addProductButton.setDisable(false);
            addProductButton.setText("Add Product");
        }
    }

    @FXML
    protected void onGotoHomePageButtonClick() throws IOException {
        try {
            App.setRoot("primarypage", HomeController.getTitle());

        } catch (Exception e) {
            System.err.println("Error loading home view: " + e.getMessage());
            e.printStackTrace();
        }
    }

}
