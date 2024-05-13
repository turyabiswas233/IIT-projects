#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node *link;
} Node;

struct node *createNode(int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->n = n;
    newNode->link = NULL;
    return newNode;
}
Node *head = NULL;

void printNode(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->n);
        ptr = ptr->link;
    }
}

void delete_kTime_node(struct node *ptr, int k)
{
    Node *preHead = ptr;
    int n = 1;
    if (k == 1)
    {
        head = NULL;
        return;
    }
    while (head != NULL)
    {
        // if (head == NULL)
        //     break;
        if ((n) % k == 0)
        {
            Node *newPtr = head->link;
            preHead->link = newPtr;
        }
        preHead = head;
        head = head->link;
        n++;
    }
    head = ptr;
}

int main(int argc, char const *argv[])
{

    Node *ptr = head;
    for (int i = 1; i <= 10; i++)
    {

        Node *newNode = createNode(i);
        if (head == NULL)
        {
            head = newNode;
            ptr = head;
            continue;
        }

        ptr->link = newNode;
        ptr = ptr->link;
    }

    int k;
    scanf("%d", &k);

    delete_kTime_node(head, k);

    printNode(head);

    return 0;
}
