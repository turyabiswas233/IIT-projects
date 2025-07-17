module com.example {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive java.sql;
    requires jbcrypt;
    requires transitive javafx.graphics;
    opens com.example to javafx.fxml;
    exports com.example;

    opens com.example.controller to javafx.fxml;
    opens com.example.controller.admin to javafx.fxml;
    opens com.example.controller.users to javafx.fxml;
    opens com.example.models to javafx.fxml;
    opens com.example.utils to javafx.fxml;

    exports com.example.controller;
    exports com.example.controller.admin;
    exports com.example.controller.users;
    exports com.example.models;
    exports com.example.utils;
}