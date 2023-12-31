#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *f1, *f2, *tmp = fopen("temp.txt", "w");
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");

    char ch;

    // write f1 data into temp file
    for (;;)
    {
        if ((ch = fgetc(f1)) == EOF)
            break;
        fputc(ch, tmp);
    }
    fclose(f1); // close f1 file as read mode

    f1 = fopen(argv[1], "w"); // open f1 file as write mode

    // write f2 data into f1
    for (;;)
    {
        if ((ch = fgetc(f2)) == EOF)
            break;
        fputc(ch, f1);
    }
    // close all file
    fclose(f1);
    fclose(f2);
    fclose(tmp);

    f2 = fopen(argv[2], "w");     // now open f2 as write mode
    tmp = fopen("temp.txt", "r"); // open temp file as read mode
    for (;;)
    {
        if ((ch = fgetc(tmp)) == EOF)
            break;
        fputc(ch, f2);
    }

    fclose(f2);
    fflush(tmp);
    fclose(tmp);

    return 0;
}
