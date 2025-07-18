package com.example;

import java.sql.Connection;
import java.sql.DriverManager; 

import java.sql.SQLException;

public class ConnectDB {

    protected static Connection connection = null;

    public static Connection getConnection() {
        return connection;
    }

    // connect to sqlite database from my local path
    public static void initDB() {
        if (connection == null)
            try {
                connection = DriverManager.getConnection("jdbc:sqlite:data.db");

                System.out.println("Database setup completed successfully.");

            } catch (SQLException e) {
                e.printStackTrace(System.err);
                closeConnection();
            }
        else {
            System.err.println("Connection already established.");
        }
    }

    public static void closeConnection() {
        try {
            if (connection != null) {
                connection.close();
            }
            else 
            System.out.println("No connection is opened");
        } catch (SQLException e) {
            e.printStackTrace(System.err);
        } finally {
            System.out.println("Connection closed.");
        }
    }
}
