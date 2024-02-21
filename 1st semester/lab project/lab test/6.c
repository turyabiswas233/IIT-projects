#include <stdio.h>
int main()
{
    char days[][700] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int day;
    do
    {
        printf("Enter day no: ");
        scanf("%d", &day);
    } while (day < 1 || day > 7);
    printf("%s", days[day - 1]);
    return 0;
}
