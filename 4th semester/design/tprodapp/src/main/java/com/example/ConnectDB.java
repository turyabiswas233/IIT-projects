package com.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import java.sql.SQLException;

public class ConnectDB {

    protected static Connection connection = null;
    protected static Statement statement = null;

    public static Connection getConnection() {
        return connection;
    }
 

    // connect to sqlite database from my local path
    public static void initDB() {
        if (connection == null || statement == null)
            try {
                connection = DriverManager.getConnection("jdbc:sqlite:data.db");
                statement = connection.createStatement();

                System.out.println("Database setup completed successfully.");

            } catch (SQLException e) {
                // if the error message is "out of memory",
                // it probably means no database file is found
                e.printStackTrace(System.err);
                closeConnection();
            }
        else {
            System.err.println("Connection already established.");
        }
    }

    public static void closeConnection() {
        try {
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace(System.err);
        } finally {
            System.out.println("Connection closed.");
        }
    }
}
