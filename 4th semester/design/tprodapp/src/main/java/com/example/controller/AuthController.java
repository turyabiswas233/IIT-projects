package com.example.controller;

import org.mindrot.jbcrypt.BCrypt;

public class AuthController {
     public static String hashPasswordString(String password) {
        String fixedSalt = BCrypt.gensalt();
        return BCrypt.hashpw(password, fixedSalt);
    }
}
