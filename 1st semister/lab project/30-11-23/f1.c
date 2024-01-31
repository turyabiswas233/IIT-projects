#include <stdio.h>
#include <stdlib.h>
void isPrime(int x)
{
    int flag = 1;
    if (x == 1)
    {
        printf("1 is neither prime nor not-prime\n");
        return;
    }
    
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            flag = 0;
    }
    if (flag)
        printf("%7d ", x);
    // else
    // {
    //     printf("%d is not prime\n", x);
    // }
}
int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        isPrime(i);
    }

    return 0;
}


//Developed by TURYA BISWAS
//Email: bsse1507@iit.du.ac.bd