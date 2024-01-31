#include <stdio.h>
#include <string.h>
union stdu
{
    /* data */
    int roll;
    char name[30];
    float cgpa;
};

struct std
{
    int roll;
    char name[30];
    float cgpa;
};

int main()
{
    int n;
    printf("How many students do you have? [1 - 50] ");
    do
    {
        scanf("%d", &n);
        if (n <= 0 || n > 50)
            printf("Wrong input, try again\nEnter Student number: ");
        /* code */
    } while (n <= 0 || n > 50);

    struct std stds[n];
    for (int i = 0; i < n; i++)
    {
        printf("Input data for student %d\n", i + 1);
        printf("Enter your name: ");
        scanf("%s", &stds[i].name);
        printf("Enter your Roll: ");
        scanf("%d", &stds[i].roll);
        printf("Enter your CGPA [0 - 4.00]: ");
        scanf("%f", &stds[i].cgpa);
    }
    // now print data

    char title[] = "\nSl No\tFull  Name\tRoll\tGrade Pt";
    int len = strlen(title);
    puts(title);
    for (int i = 0; i < len; i++)
    {
        if (title[i] == '\n')
            continue;
        if (title[i] == '\t')
            printf("\t");
        else
            printf("=");
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%3d\t", i + 1);
        printf("%8s\t%3d\t%6.2f", stds[i].name, stds[i].roll, stds[i].cgpa);
    }
    return 0;
}
