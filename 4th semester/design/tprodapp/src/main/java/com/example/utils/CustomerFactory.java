package com.example.utils;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.example.ConnectDB;
import com.example.models.Customer;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class CustomerFactory {

    private static ObservableList<Customer> customerList = FXCollections.observableArrayList();

    public static ObservableList<Customer> loadCustomers() {
        ConnectDB.initDB();

        try (PreparedStatement pstmt = ConnectDB.getConnection().prepareStatement("SELECT * FROM customers")) {
            ResultSet rs = pstmt.executeQuery();
            customerList.clear();

            while (rs.next()) {
                customerList.add(new Customer(rs.getInt("id"), rs.getString("name"), rs.getString("phone")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return customerList;
    }
}
