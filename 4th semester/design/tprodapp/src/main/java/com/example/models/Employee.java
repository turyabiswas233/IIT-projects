package com.example.models;
import javafx.beans.property.*;

public class Employee {
    private IntegerProperty id;
    private StringProperty name;
    private StringProperty email;
    private StringProperty phone;

    public Employee(int id, String name, String email, String phone) {
        this.id = new SimpleIntegerProperty(id);
        this.name = new SimpleStringProperty(name);
        this.email = new SimpleStringProperty(email);
        this.phone = new SimpleStringProperty(phone);
    }
    
    
    @Override
    public String toString() {
        return "User [id=" + id + ", name=" + name + ", email=" + email + ", phone=" + phone 
                + "]";
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

    public String getPhone() {
        return phone.get();
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

    public StringProperty getPhoneProperty() {
        return phone;
    }

    
}
