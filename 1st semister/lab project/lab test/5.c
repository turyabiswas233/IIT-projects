#include <stdio.h>
int rate(int salary)
{
    if (salary <= 1000)
        return 5;
    else if (salary <= 2000)
        return 10;
    else
        return 20;
}
int main(int argc, char const *argv[])
{
    int sal;
    printf("Enter your salary: ");
    scanf("%d", &sal);
    printf("Commission: %0.2f BDT", rate(sal) * sal / 100.0);
    return 0;
}
