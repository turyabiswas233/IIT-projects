#include <stdio.h>
#include <string.h>
float calcGPA(int mark1,int n);
void setGrade(int mark, char *ltGrade, float *point);

int main()
{
    int n = 5,sum = 0;
    int mark[n][3];
    float points[n],credSum = 0, gpaSum = 0;
    char ltGrade[n][4];
    float *gpa;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d%d%d", &mark[i][0], &mark[i][1], &mark[i][2]);//take input for each 
    }

    char title[100] = "Sub Code  Credit  Marks  Lt Grade  Grade Pt";
    printf("\n%s\n", title);
    int t_len = strlen(title);
    for (size_t i = 0; i < t_len; i++)
    {
        /* code */
        if (title[i] == ' ' && title[i + 1] == ' ')
        {
            printf("  ");
            i++;
        }
        else
            printf("=");
    }
    printf("\n");
    for (size_t i = 0; i < n; i++)
    {

        setGrade(mark[i][2], ltGrade[i], points + i);
        credSum+= mark[i][1];
        gpaSum+=mark[i][1] * points[i];
        printf("%5d%8d%9d%8s\t%9.2f\n", mark[i][0], mark[i][1], mark[i][2], ltGrade[i], *(points + i));
    }
    printf("\n");
    for (size_t i = 0; i < t_len; i++)
    {
        printf("-");
    }
    printf("\n\n");
    printf("GPA = %0.2f\n", gpaSum/credSum);

    return 0;
}
float calcGPA(int mark1, int n)
{
    float mark = mark1/n*1.0;
    if (mark < 40)
    {

        return 0.00;
    }

    else if (mark < 45)
    {

        return 2;
    }

    else if (mark < 50)
    {

        return 2.25;
    }
    else if (mark < 55)
    {

        return 2.5;
    }

    else if (mark < 60)
    {

        return 2.75;
    }

    else if (mark < 65)
    {

        return 3;
    }
    else if (mark < 70)
    {

        return 3.25;
    }

    else if (mark < 75)
    {

        return 3.5;
    }

    else if (mark < 80)
    {

        return 3.75;
    }
    else
    {

        return 4;
    }
}

void setGrade(int mark, char *ltGrade, float *point)
{
    if (mark < 40)
    {
        strcpy(ltGrade, "F");
        *point = 0.00;
    }

    else if (mark < 45)
    {
        strcpy(ltGrade, "D");
        *point = 2;
    }

    else if (mark < 50)
    {
        strcpy(ltGrade, "C");
        *point = 2.25;
    }
    else if (mark < 55)
    {
        strcpy(ltGrade, "C+");
        *point = 2.5;
    }

    else if (mark < 60)
    {
        strcpy(ltGrade, "B-");
        *point = 2.75;
    }

    else if (mark < 65)
    {
        strcpy(ltGrade, "B");
        *point = 3;
    }
    else if (mark < 70)
    {
        strcpy(ltGrade, "B+");
        *point = 3.25;
    }

    else if (mark < 75)
    {
        strcpy(ltGrade, "A-");
        *point = 3.5;
    }

    else if (mark < 80)
    {
        strcpy(ltGrade, "A");
        *point = 3.75;
    }
    else
    {
        strcpy(ltGrade, "A+");
        *point = 4;
    }
}
