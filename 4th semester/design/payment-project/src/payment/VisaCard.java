package payment;

import java.time.LocalDateTime;

public class VisaCard extends PaymentMethod {
    float discount = 5.0f;

    public VisaCard(String accountNumber, float balance, String cardHolderName, LocalDateTime expiry, String type) {
        super(accountNumber, balance, cardHolderName, expiry, type);
    }

    @Override
    float calculatePayableAmount(float amount) {
        return amount - amount * discount / 100.0f;
    }

}
