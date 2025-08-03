package com.example.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.print.PrinterJob;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.text.Text;

import java.util.Date;

import com.example.models.InvoiceItem;

public class InvoiceController {

    @FXML
    private Text invoiceNumberText;
    @FXML
    private Text invoiceDateText;
    @FXML
    private Text customerNameText;
    @FXML
    private Text customerPhoneText;
    @FXML
    private TableView<InvoiceItem> orderItemsTable;
    @FXML
    private TableColumn<InvoiceItem, String> itemNameColumn;
    @FXML
    private TableColumn<InvoiceItem, Integer> quantityColumn;
    @FXML
    private TableColumn<InvoiceItem, Double> unitPriceColumn;
    @FXML
    private TableColumn<InvoiceItem, Double> lineTotalColumn;
    @FXML
    private Text subtotalText;
    @FXML
    private Text taxText;
    @FXML
    private Text shippingText;
    @FXML
    private Text grandTotalText;

    private ObservableList<InvoiceItem> invoiceItems = FXCollections.observableArrayList();

    public void initialize() {
        // Initialize TableView columns
        itemNameColumn.setCellValueFactory(new PropertyValueFactory<>("productName"));
        quantityColumn.setCellValueFactory(new PropertyValueFactory<>("quantity"));
        unitPriceColumn.setCellValueFactory(new PropertyValueFactory<>("unitPrice"));
        lineTotalColumn.setCellValueFactory(new PropertyValueFactory<>("lineTotal"));
        orderItemsTable.setItems(invoiceItems);
    }

    public void setInvoiceData(String invoiceNumber, String customerName, String customerPhone,
            ObservableList<InvoiceItem> items) {
        invoiceNumberText.setText(invoiceNumber);
        invoiceDateText.setText(new Date().toString());
        customerNameText.setText(customerName);
        customerPhoneText.setText(customerPhone);
        invoiceItems.addAll(items);
        calculateTotals();
    }

    private void calculateTotals() {
        double subtotal = invoiceItems.stream().mapToDouble(item -> item.getLineTotal().get()).sum();
        double tax = subtotal * 0.05; // 5% tax
        double shipping = 5.00; // Example shipping cost
        double grandTotal = subtotal + tax + shipping;

        subtotalText.setText(String.format("%.2f", subtotal));
        taxText.setText(String.format("%.2f", tax));
        shippingText.setText(String.format("%.2f", shipping));
        grandTotalText.setText(String.format("%.2f", grandTotal));
    }

    @FXML
    public void printInvoice() {
        PrinterJob job = PrinterJob.createPrinterJob();
        if (job != null && job.showPrintDialog(orderItemsTable.getScene().getWindow())) {
            boolean success = job.printPage(orderItemsTable.getScene().getRoot());
            if (success) {
                job.endJob();
            }
        }
    }
}
