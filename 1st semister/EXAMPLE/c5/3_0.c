#include <stdio.h>
#define n 5
int main(int argc, char const *argv[])
{
    char temp[100] = "তূর্য বিশ্বাস ";
    FILE *fp = fopen("data.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "\t");
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                fputs("\t", fp);
                for (int l = 0; l < n; l++)
                {
                    fprintf(fp, "%s", temp);
                }
            }
            fprintf(fp, "\n\t");
        }
        fprintf(fp, "\n");
    }
    printf("success!!\n");
    fclose(fp);

    return 0;
}
