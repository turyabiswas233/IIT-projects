package payment;

import java.time.LocalDateTime;

public class MobileBanking extends PaymentMethod {

    float charge = 1.0f;

    public MobileBanking(String accountNumber, float balance, String cardHolderName, LocalDateTime expiry,
            String type) {
        super(accountNumber, balance, cardHolderName, expiry, type);
    }

    @Override
    float calculatePayableAmount(float amount) {
        return amount + amount * charge / 100;
    }

}
