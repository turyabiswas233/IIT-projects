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

    
    
    public int getId() {
        return id.get();
    }

    public String getName() {
        return name.get();
    }

    public String getEmail() {
        return email.get();
    }

    public String getPassword() {
        return password.get();
    }

    public String getRole() {
        return role.get();
    }

    public IntegerProperty getIdProperty() {
        return id;
    }
    public StringProperty getNameProperty() {
        return name;
    }

    public StringProperty getEmailProperty() {
        return email;
    }

    public StringProperty getPasswordProperty() {
        return password;
    }

    public StringProperty getRoleProperty() {
        return role;
    }   
}
