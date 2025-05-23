package com.example;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class PrimaryController {
    private int number = 0;
    private @FXML Button incrementButton;
    private @FXML Button decrementButton;
    private @FXML Label numberBox;

    @FXML
    private void addNumber() throws IOException {
        this.number+=1;
        if(this.number > 9){
            toggleAddButton(false);
            toggleRemoveButton(true);
        }
        else {
            toggleAddButton(true);
            toggleRemoveButton(false);
        }
        updateNumber();
    }

    @FXML
    private void removeNumber() throws IOException {
        this.number-=1;
        if(this.number < 1){
            toggleRemoveButton(false);
            toggleAddButton(true);
        }
        else {
            toggleRemoveButton(true);
            toggleAddButton(false);
        }
        updateNumber();
    }

    private void updateNumber() {
        numberBox.setText(String.valueOf(this.number));
    }

    private void toggleRemoveButton(boolean isVisible) {
        decrementButton.setVisible(isVisible);
    }
    private void toggleAddButton(boolean isVisible) {
        incrementButton.setVisible(isVisible);
    }
}
