import java.time.LocalDateTime;
import java.util.ArrayList;

import payment.MobileBanking;
import payment.PaymentMethod;
import payment.VisaCard;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Payment Method List:");
        ArrayList<String> paymentMethodList = new ArrayList<>();
        paymentMethodList.add("VISA_CARD");
        paymentMethodList.add("Mobile Banking");

        for (String iterable_element : paymentMethodList) {
            System.out.println((paymentMethodList.indexOf(iterable_element)+1) + ". " + iterable_element);
        }

        PaymentMethod pm1 = new VisaCard("4220213565587785", 1999, "TURYA BISWAS", LocalDateTime.of(2032, 4, 25, 0, 0, 0), "VISA_CARD");
        PaymentMethod pm2 = new MobileBanking("01540153569", 99, "TURYA BISWAS", LocalDateTime.of(2022, 4, 25, 0, 0, 0), "BKASH");

        System.out.println(pm1);
        System.out.println(pm2);

        pm1.pay(3500);
        pm2.pay(50);

        
    }
}
