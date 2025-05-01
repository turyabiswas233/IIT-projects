#include <stdio.h>
#include <stdlib.h>
struct node
{
    char character;
    int frequency;

    struct node *next;
    struct node *left;
    struct node *right;
};
struct node *start = NULL;
struct node *List[10];
void INIT()
{
    for (int i = 0; i < 10; i++)
    {
        List[i] = NULL;
    }
}
void INSERT(struct node *z)
{
    for (int i = 0; i < 6; i++)
    {
        if (List[i] == NULL)
        {
            List[i] = z;
            break;
        }
    }
}

struct node *createNode(char q, int freq)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->character = q;
    newNode->frequency = freq;
    newNode->next = NULL;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct node *extractMin(struct node *Q)
{
    int min = Q->frequency;
    struct node *ptr = Q;
    while (ptr != NULL)
    {
        if (ptr->next != NULL)
            if (ptr->frequency > ptr->next->frequency)
            {
                min = ptr->next->frequency;
            }
        ptr = ptr->next;
    }

    struct node *newPtr;
    ptr = Q;
    while (ptr != NULL)
    {
        if (ptr->frequency == min)
        {
            return ptr;
        }

        ptr = ptr->next;
    }
}
struct node *HUFFMAN(struct node *C)
{

    struct node *Q = C;

    struct node *z = malloc(sizeof(struct node));
    struct node *x;
    struct node *y;
    x = z->left = extractMin(Q);
    Q = Q->next;
    y = z->right = extractMin(Q);

    z->frequency = x->frequency + y->frequency; // jani na :)
    // printf("%d\n", z->frequency);
    INSERT(z); // Q dei nai, cz, Q er data to Z e already entry hoia ase left and right leaf e

    return extractMin(Q); // eta complete i hope
}

int main()
{
    start = createNode('f', 5);
    start->next = createNode('e', 9);
    start->next->next = createNode('c', 12);
    start->next->next->next = createNode('b', 13);
    start->next->next->next->next = createNode('d', 16);
    start->next->next->next->next->next = createNode('a', 45);

    INIT();
    struct node *ptr = start;
    while (ptr->next != NULL)
    {

        HUFFMAN(ptr);
        ptr = ptr->next;
    }

    for (int i = 0; i < 6; i++)
    {
        /* code */
        if (List[i] != NULL)
        {
            printf("%d-%d\n", List[i]->left->frequency, List[i]->right->frequency);
            // printf("%d\n", List[i]->frequency);
        }
    }
    // eta to tree er kono part na.
    // huffman er ekta part holo tree.
    // huffman er code korte tree lage. boi te hoyto tui tree er merge kora kono code er example pabi.
    // hu hu
    return 0;
}
/*
    terminal e 5+5=10
                9+9 = 18;
                emon hoitese.
                we need, 5+9=14
                then, 12+13=25

*/