#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stdData
{
    char name[30]; // 30
    int marks[6];  // 24
    float cgpa;    // 6
} std;

int main(int argc, char const *argv[])
{
    FILE *fp;
    char str[100];
    fp = fopen("myStdRes.dat", "w");
    if (fp == NULL)
    {
        perror("Wrong file_name");
        exit(1);
    }
    printf("Size of std: %uB (%uB)\n", sizeof(std), sizeof(std.cgpa) + sizeof(std.marks) + sizeof(std.name));
    printf("Size of std[cgpa,makrs,name]: %uB %uB %uB\n", sizeof(std.cgpa), sizeof(std.marks), sizeof(std.name));

    fclose(fp);

    return 0;
}
