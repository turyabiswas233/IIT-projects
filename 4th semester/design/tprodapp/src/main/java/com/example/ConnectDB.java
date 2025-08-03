package com.example;

import java.sql.Connection;
import java.sql.DriverManager;

import java.sql.SQLException;

public class ConnectDB {

    protected static Connection connection = null;

    private ConnectDB() {

    }

    public static Connection getConnection() {
        return connection;
    }

    // connect to sqlite database from my local path
    public static void initDB() {

        if (connection == null) {
            // init db
            try {
                connection = DriverManager.getConnection("jdbc:sqlite:data.db");

                System.out.println("Database setup completed successfully.");

            } catch (SQLException e) {
                System.out.println("ERROR IN CONNECT-DB");
                e.printStackTrace();
            }
        } else {
            System.err.println("Connection already established.");
        }

    }

    public static void closeConnection() {
        try {
            if (connection != null) {
                connection.close();
                System.out.println("Connection closed.");
            } else
                System.out.println("No connection is opened");
        } catch (SQLException e) {
            System.out.println("FAILED to disconnect connection");
            e.printStackTrace(System.err);
        }
    }
}
