// #include <stdio.h>
#include "mHead.h"

int main(int argc, char const *argv[])
{
    node *head = NULL;
    node *temp;
    int n, x;
    freopen(argv[1], "r", stdin);
    scanf("%d", &n);
    if (n == 0)
        return 1;
    for (int i = 0; i < n; i++)
    {

        scanf(" %d", &x);
        if (i == 0)
        {
            temp = createNode(x);
            head = temp;
        }
        else
        {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    tree *root = NULL;
    temp = head;
    while (temp)
    {

        root = createBst(root, temp);
        temp = temp->next;
    }
    inorder(root);
    printf("\n#TOTAL DATA: %d\n", n);
    printf("#DATA TYPE: {int age, string name}\n");

    printf("\n");

    return 0;
}
