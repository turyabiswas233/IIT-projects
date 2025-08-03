
package com.example.models;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class InvoiceItem {
    private IntegerProperty orderId;
    private IntegerProperty productId;
    private IntegerProperty customerId;
    private StringProperty productName;
    private IntegerProperty quantity;
    private DoubleProperty unitPrice;
    private DoubleProperty lineTotal;

    public InvoiceItem(int orderId, int productId, int customerId, String productName, int quantity, double unitPrice) {
        this.orderId = new SimpleIntegerProperty(orderId);
        this.productId = new SimpleIntegerProperty(productId);
        this.customerId = new SimpleIntegerProperty(customerId);
        this.productName = new SimpleStringProperty(productName);
        this.quantity = new SimpleIntegerProperty(quantity);
        this.unitPrice = new SimpleDoubleProperty(unitPrice);
        this.lineTotal = new SimpleDoubleProperty(quantity * unitPrice);
    }

    public InvoiceItem(String productName, int quantity, double unitPrice, double lineTotal) {
        this.productName = new SimpleStringProperty(productName);
        this.quantity = new SimpleIntegerProperty(quantity);
        this.unitPrice = new SimpleDoubleProperty(unitPrice);
        this.lineTotal = new SimpleDoubleProperty(lineTotal);
    }

    public IntegerProperty getOrderId() {
        return orderId;
    }

    public void setOrderId(IntegerProperty orderId) {
        this.orderId = orderId;
    }

    public IntegerProperty getProductId() {
        return productId;
    }

    public void setProductId(IntegerProperty productId) {
        this.productId = productId;
    }

    public IntegerProperty getCustomerId() {
        return customerId;
    }

    public void setCustomerId(IntegerProperty customerId) {
        this.customerId = customerId;
    }

    public StringProperty getProductName() {
        return productName;
    }

    public void setProductName(StringProperty productName) {
        this.productName = productName;
    }

    public IntegerProperty getQuantity() {
        return quantity;
    }

    public void setQuantity(IntegerProperty quantity) {
        this.quantity = quantity;
    }

    public DoubleProperty getUnitPrice() {
        return unitPrice;
    }

    public void setUnitPrice(DoubleProperty unitPrice) {
        this.unitPrice = unitPrice;
    }

    public DoubleProperty getLineTotal() {
        return lineTotal;
    }

    public void setLineTotal(DoubleProperty lineTotal) {
        this.lineTotal = lineTotal;
    }

    

}
