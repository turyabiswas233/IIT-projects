package com.example.controller;

public class AuthController {
    public static String hashPasswordString(String password) {
        return "15" + password + "07";
    }

    public static boolean checkPasswordString(String password, String hashPw) {
        return hashPw.equals(password);
    }
}
