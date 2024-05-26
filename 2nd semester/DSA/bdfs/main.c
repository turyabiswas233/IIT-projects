#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define inf 50
#define size 5

struct queue
{
    int *p;
    int len;
    int front;
    int rear;
};
int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}
int dequeue(struct queue *q)
{
    int a;
    if (isEmpty(q) == 1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        q->front++;
        a = q->p[q->front];
    }
    return a;
}
void enqueue(struct queue *q, int a)
{
    if (q->rear == q->len)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->p[q->rear] = a;
}
int main(int argc, char const *argv[])
{

    int u;
    int i;
    char color[size] = {'w', 'w', 'w', 'w', 'w'};
    int a[size][size] = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
    };

    for (i = 0; i < size; i++)
    {
        printf("\n%d-> ", i);
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] == 1)
            {
                printf(" %d", j);
            }
        }
    }
    printf("\n");
    i = 2;
    printf("%d\n", i);
    color[i] = 'g';
    struct queue q;
    q.len = 50;
    q.front = q.rear = 0;
    q.p = (int *)malloc(sizeof(int) * q.len); // empty queue
    enqueue(&q, i);                           // enqueue

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);        // get and remove index from queue
        for (int j = 0; j < size; j++) // for each V E adj[a]
        {
            if (a[node][j] == 1 && color[j] == 'w')
            {
                printf("%d ", j);
                color[j] = 'g';
                if (j == 1)
                    break;
                enqueue(&q, j);
            }
        }
        color[node] = 'b';
    }
}
