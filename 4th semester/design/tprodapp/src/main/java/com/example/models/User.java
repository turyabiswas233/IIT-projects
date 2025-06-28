package com.example.models;

import javafx.beans.property.*;

public class User {
    private IntegerProperty id;
    private StringProperty name;
    private StringProperty email;
    private StringProperty password;
    private StringProperty role;

    public User(String name, String email, String password, String role) {
        this.id = new SimpleIntegerProperty();
        this.name = new SimpleStringProperty(name);
        this.email = new SimpleStringProperty(email);
        this.password = new SimpleStringProperty(password);
        this.role = new SimpleStringProperty(role);
    }

    public User(int id, String name, String email, String password, String role) {
        this.id = new SimpleIntegerProperty(id);
        this.name = new SimpleStringProperty(name);
        this.email = new SimpleStringProperty(email);
        this.password = new SimpleStringProperty(password);
        this.role = new SimpleStringProperty(role);
    }

    public IntegerProperty getId() {
        return id;
    }

    public StringProperty getName() {
        return name;
    }

    public StringProperty getEmail() {
        return email;
    }

    public StringProperty getPassword() {
        return password;
    }

    public StringProperty getRole() {
        return role;
    }   
}
