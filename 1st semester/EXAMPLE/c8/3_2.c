#include <stdio.h>
#include <conio.h>
int main()
{
    double amount = 0.2;
    cprintf("printing 5 - percent tax table \n \r");
    cprintf("Press a key to stop.\n\n\r");
    do
    {
        cprintf("amount: %f, tax: %f\n\r", amount, amount * 0.05);
        if (kbhit())
            break;
        amount = amount + 0.20;
    } while (amount < 100000.0);
    return 0;
}