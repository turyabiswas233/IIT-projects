#include <stdio.h>

void my_strcat(char *to, const char *from)
{
    // Copy characters from source to destination
    while (*to != '\0')
    {
        to++;
    }

    while (*from != '\0')
    {
        *to = *from;
        from++;
        to++;
    }
    // Add null terminator to the destination string
    *to = '\0';
}

int main()
{
    // Example usage of custom strcpy function
    char *source = "turya";
    char destination[100] = "Hello, ";

    printf("Before cat\t: source: %s\n", source);
    printf("Before cat\t: Destination: %s\n", destination);
    // Copying the string using custom strcpy function
    my_strcat(destination, source);

    // Print the copied string
    printf("After cat\t: Destination: %s\n", destination);

    return 0;
}
