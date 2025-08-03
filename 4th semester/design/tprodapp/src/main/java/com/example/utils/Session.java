package com.example.utils;

public class Session {
    private static String role = null;

    public static void setRole(String roleString) {
        System.out.println("ROLE: "+ roleString);
        role = roleString;
    }

    public static void clearAll() {
        role = null;
    }

    public static String getRole() {
        return role;
    }
}
