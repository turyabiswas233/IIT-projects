package com.example.controller;

import org.mindrot.jbcrypt.BCrypt;

public class AuthController {
     public static String hashPasswordString(String password) {
        return BCrypt.hashpw(password, BCrypt.gensalt());
    }

    public static boolean checkPasswordString(String password, String hashPw) {
        return BCrypt.checkpw(password, hashPw);
    }
}
