package com.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.sql.SQLException;

public class ConnectDB {
    // connect to sqlite database from my local path
    private static final String DB_URL = "jdbc:sqlite:/home/turya07/Documents/IIT-projects/4th semester/design/tprodapp/data.db";
    private static List<String> tableNames = new ArrayList<>();

    // now check connection
    public static void main(String[] args) {
        try (Connection conn = DriverManager.getConnection(DB_URL)) {
            if (conn != null) {
                System.out.println("Connected to the database.");
                showTables();
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    // show all tables in the database
    public static void showTables() {
        String sql = "SELECT name FROM sqlite_master WHERE type='table'";
        try (Connection conn = DriverManager.getConnection(DB_URL);
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {
            while (rs.next()) {
                tableNames.add(rs.getString("name"));
            }

            // show all tables
            System.out.println("Tables in the database:");
            System.out.println();
            tableNames.forEach(ele -> {
                System.out.println("#Data in table: " + ele);
                showColumns(ele);
            });

        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    // show all columns in the tabls
    public static void showColumns(String tableName) {
        String sql = "select * from " + tableName;
        try (Connection conn = DriverManager.getConnection(DB_URL);
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql)) {
            while (rs.next()) {
                for (int i = 1; i <= rs.getMetaData().getColumnCount(); i++) {
                    System.out.print(rs.getMetaData().getColumnName(i) + ": " + rs.getString(i) + "\t");
                }
                System.out.println();
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

}
