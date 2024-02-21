#include <stdio.h>
int main()
{
    int p, count = 1, checker = 1;
    char a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', i = '9';
    while (1)
    {

        printf(" %c | %c | %c \n", a, b, c);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", d, e, f);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", g, h, i);
        if ((a ==  'O' && b== 'O' && c== 'O') ||(d ==  'O' && e== 'O' && f== 'O')  ||(g ==  'O' && h== 'O' && i== 'O')  || (a ==  'O' && d== 'O' && g== 'O')  || (h ==  'O' && b== 'O' && e== 'O')  || (c ==  'O' && f== 'O' && i== 'O')  || (a ==  'O' && e== 'O' && i== 'O')  || (e ==  'O' && g== 'O' && c== 'O') )
        {
            printf("\n\tPlayer 1 winner!!\n");
            break;
        }
        else if ((a ==  'X' && b== 'X' && c== 'X') ||(d ==  'X' && e== 'X' && f== 'X')  ||(g ==  'X' && h== 'X' && i== 'X')  || (a ==  'X' && d== 'X' && g== 'X')  || (h ==  'X' && b== 'X' && e== 'X')  || (c ==  'X' && f== 'X' && i== 'X')  || (a ==  'X' && e== 'X' && i== 'X')  || (e ==  'X' && g== 'X' && c== 'X') )
        {
            printf("\n\tPlayer 2 winner!!\n");
            break;
        }
        printf("\n\tEnter a number from 1 to 9 user(%d): ", count == 1 ? 1 : 2);
        scanf("%d", &p);
        if (checker >= 9)
        {
            printf("\n\tMatch draw\n");
            break;
        }
        else if (p < 1 || p > 9)
        {
            printf("Wrong input, try again\n");
            continue;
        }
        switch (p)
        {
        case 1:
            if (a == 'X' || a == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }
            a = count == 1 ? 'O' : 'X';
            break;
        case 2:
            if (b == 'X' || b == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            b = count == 1 ? 'O' : 'X';
            break;
        case 3:
            if (c == 'X' || c == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            c = count == 1 ? 'O' : 'X';
            break;
        case 4:
            if (d == 'X' || d == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            d = count == 1 ? 'O' : 'X';
            break;
        case 5:
            if (e == 'X' || e == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            e = count == 1 ? 'O' : 'X';
            break;
        case 6:
            if (f == 'X' || f == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            f = count == 1 ? 'O' : 'X';
            break;
        case 7:
            if (g == 'X' || g == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            g = count == 1 ? 'O' : 'X';
            break;
        case 8:
            if (h == 'X' || h == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            h = count == 1 ? 'O' : 'X';
            break;
        case 9:
            if (i == 'X' || i == 'O')
            {
                printf("Wrong input, try again\n");
                continue;
            }

            i = count == 1 ? 'O' : 'X';
            break;

        default:

            break;
        }
        count = count == 1 ? 0 : 1;
        checker++;
    }
    return 0;
}