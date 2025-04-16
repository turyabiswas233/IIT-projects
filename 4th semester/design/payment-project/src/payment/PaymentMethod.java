package payment;
import java.time.LocalDateTime;

public abstract class PaymentMethod implements PaymentStrategy {
    
    float balance;
    String accountNumber;
    String cardHolderName;
    String type;
    LocalDateTime expiry;

    public PaymentMethod(String accountNumber, float balance, String cardHolderName, LocalDateTime expiry, String type) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.cardHolderName = cardHolderName;
        this.expiry = expiry;
        this.type = type;
    }


    abstract float calculatePayableAmount(float amount);


    boolean isExpired(){
        return expiry.isBefore(LocalDateTime.now());
    }

    boolean isNotPayable(float amount){
        return  amount > this.balance;
    }

    @Override
    public boolean pay(float amount){
        if(isExpired()) {
            System.err.println("CARD IS EXPIRED\n");
            return false;
        }
        float payableAmount = calculatePayableAmount(amount);
        System.out.println("Requested Amount: "+payableAmount+" BDT");
        if(isNotPayable(payableAmount)){
            System.err.println("INSUFFICIENT BALANCE: required "+ (payableAmount-this.balance)+" BDT\n");
            return false;
        }

        System.out.println("Successfully PAID\n");
        this.balance = this.balance - payableAmount;
        return true;
    }


    @Override
    public String toString() {
        return "\n"+ this.type.toUpperCase().toString() + ":\n[\n\tBalance= " + balance + " BDT\n\tAccountNumber= " + accountNumber + "\n\tCardHolderName= "
                + cardHolderName + "\n\tExpiry= " + expiry + "\n]\n";
    }

    
}
