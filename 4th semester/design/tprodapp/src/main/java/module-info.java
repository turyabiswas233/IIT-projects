module com.example {
    requires javafx.controls;
    requires javafx.fxml;
    requires transitive java.sql;
    requires jbcrypt;
    requires transitive javafx.graphics;
    opens com.example to javafx.fxml;
    exports com.example;

    opens com.example.controller to javafx.fxml;
    opens com.example.models to javafx.fxml;

    exports com.example.controller;
    exports com.example.models;
}