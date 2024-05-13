#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char info;
    struct tree *child;
    struct tree *sibl;
} T;
void printTree(T *ptr)
{
    while (ptr->child != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->child;
    }
}
int main(int argc, char const *argv[])
{
    T *tree = (T *)malloc(sizeof(T));
    char list[] = {'a',
                   'b',
                   'c',
                   'd',
                   'e',
                   'f',
                   'g',
                   'h',
                   'i',
                   'j',
                   'k'};

    T *ptr = tree;
    for (int i = 0; i < 11; i++)
    {
        /* code */
        T *newNode = (T *)malloc(sizeof(T));
        newNode->info = list[i];
        newNode->child = NULL;
        newNode->sibl = NULL;
        tree = newNode;
        tree = tree->child;
    }
    tree = ptr;
    printTree(tree);

    return 0;
}
