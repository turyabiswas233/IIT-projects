package com.example.controller;

import com.example.PageLoader;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.io.IOException;

public class HomeController implements Controller {
    private Stage stage;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @Override
    public String getTitle() {
        return "Tb Product Management";
    }

    @FXML
    protected void onGotoLoginPageButtonClick() throws IOException {
        try {
            LoginController loginController = new LoginController();
            this.stage = loginController.setStage(this.stage);
            Scene scene = new Scene(PageLoader.loadFXML("loginview", loginController));
            stage.setScene(scene);

        } catch (Exception e) {
            System.err.println("Error loading login view: " + e.getMessage());
            e.printStackTrace();
        } finally {
            stage.close();
            stage.show();
        }
    }

    @FXML
    protected void onGotoSignupButtonClick() throws IOException {
        try {
            RegisterController registerController = new RegisterController();
            this.stage = registerController.setStage(this.stage);
            Scene scene = new Scene(PageLoader.loadFXML("signup", registerController));
            stage.setScene(scene);

        } catch (Exception e) {
            System.err.println("Error loading signup view: " + e.getMessage());
            e.printStackTrace();
        } finally {
            stage.close();
            stage.show();
        }
    }

    @FXML
    protected void onGotoDashboardButtonClick() throws IOException {
        try {
            DashboardController productController = new DashboardController();
            this.stage = productController.setStage(this.stage);
            Scene scene = new Scene(PageLoader.loadFXML("dashboard", productController));
            stage.setScene(scene);

        } catch (Exception e) {
            System.err.println("Error loading dashboard view: " + e.getMessage());
            e.printStackTrace();
        } finally {
            stage.close();
            stage.show();
        }
    }
}