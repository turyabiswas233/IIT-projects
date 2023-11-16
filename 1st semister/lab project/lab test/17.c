// ascending
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter %d integer numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
        printf("%d ", ar[i]);
    }

    return 0;
}
