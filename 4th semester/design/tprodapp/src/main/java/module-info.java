module com.example {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires jbcrypt;
    opens com.example to javafx.fxml;
    exports com.example;

    opens com.example.controller to javafx.fxml;
    exports com.example.controller;
}