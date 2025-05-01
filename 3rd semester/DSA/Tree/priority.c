#include <stdio.h>
#include <stdlib.h>
#include "priority.h"

int main(int argc, char const *argv[])
{
    int n;
    freopen(argv[1], "r", stdin);
    scanf("%d", &n);
    queue *q = malloc(sizeof(queue));
    initQueue(q, n);
    for (int i = 0; i < n; i++)
    {
        int priority;
        string data = malloc(sizeof(char) * 6);

        scanf(" %d", &priority);
        scanf(" %s", data);
        push(q, createNode(data, priority));
    }
    while (isEmpty(q) == 0)
    {
        node *n = pop(q);
        printf("%d-> %s\n", n->priority, n->data);
    }
    resetQueue(q);
    quickSort(q->arr, q->front, q->rear - 1);
    while (isEmpty(q) == 0)
    {
        node *n = pop(q);
        printf("%d-> %s\n", n->priority, n->data);
    }

    return 0;
}
