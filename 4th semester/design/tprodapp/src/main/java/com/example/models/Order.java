package com.example.models;

import javafx.beans.property.*;

public class Order {

    private final IntegerProperty id;
    private final IntegerProperty customerId;
    private final IntegerProperty productId;
    private final IntegerProperty quantity;
    private final StringProperty orderDate;
    private final StringProperty customerName;
    private final StringProperty productName;
    private final DoubleProperty totalPrice;

    public Order(int id, int customerId, int productId, int quantity, String orderDate) {
        this.id = new SimpleIntegerProperty(id);
        this.customerId = new SimpleIntegerProperty(customerId);
        this.productId = new SimpleIntegerProperty(productId);
        this.quantity = new SimpleIntegerProperty(quantity);
        this.orderDate = new SimpleStringProperty(orderDate);
        this.customerName = new SimpleStringProperty("");
        this.productName = new SimpleStringProperty("");
        this.totalPrice = new SimpleDoubleProperty(0.0);
    }

    public Order(int customerId, int productId, int quantity, String orderDate, String customerName, String productName, double totalPrice) {
        this.id = new SimpleIntegerProperty(0);
        this.customerId = new SimpleIntegerProperty(customerId);
        this.productId = new SimpleIntegerProperty(productId);
        this.quantity = new SimpleIntegerProperty(quantity);
        this.orderDate = new SimpleStringProperty(orderDate);
        this.customerName = new SimpleStringProperty(customerName);
        this.productName = new SimpleStringProperty(productName);
        this.totalPrice = new SimpleDoubleProperty(totalPrice);
    }

    @Override
    public String toString() {
        return "Order{" +
                "id=" + id.get() +
                ", customerId=" + customerId.get() +
                ", productId=" + productId.get() +
                ", quantity=" + quantity.get() +
                ", orderDate='" + orderDate.get() + '\'' +
                ", customerName='" + customerName.get() + '\'' +
                ", productName='" + productName.get() + '\'' +
                ", totalPrice=" + totalPrice.get() +
                '}';
    }

    // Getters
    public int getId() {
        return id.get();
    }

    public int getCustomerId() {
        return customerId.get();
    }

    public int getProductId() {
        return productId.get();
    }

    public int getQuantity() {
        return quantity.get();
    }

    public String getOrderDate() {
        return orderDate.get();
    }

    public String getCustomerName() {
        return customerName.get();
    }

    public String getProductName() {
        return productName.get();
    }

    public double getTotalPrice() {
        return totalPrice.get();
    }

    // Setters
    public void setId(int id) {
        this.id.set(id);
    }

    public void setCustomerId(int customerId) {
        this.customerId.set(customerId);
    }

    public void setProductId(int productId) {
        this.productId.set(productId);
    }

    public void setQuantity(int quantity) {
        this.quantity.set(quantity);
    }

    public void setOrderDate(String orderDate) {
        this.orderDate.set(orderDate);
    }

    public void setCustomerName(String customerName) {
        this.customerName.set(customerName);
    }

    public void setProductName(String productName) {
        this.productName.set(productName);
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice.set(totalPrice);
    }

    // Property getters for JavaFX binding
    public IntegerProperty idProperty() {
        return id;
    }

    public IntegerProperty customerIdProperty() {
        return customerId;
    }

    public IntegerProperty productIdProperty() {
        return productId;
    }

    public IntegerProperty quantityProperty() {
        return quantity;
    }

    public StringProperty orderDateProperty() {
        return orderDate;
    }

    public StringProperty customerNameProperty() {
        return customerName;
    }

    public StringProperty productNameProperty() {
        return productName;
    }

    public DoubleProperty totalPriceProperty() {
        return totalPrice;
    }
}
