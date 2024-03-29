#include <stdio.h>
#define queue_size 10000
#define endl printf("\n")

typedef struct
{
    int (*size)(void);
    int (*empty)(void);
    int (*top)(void);
    int (*back)(void);
    void (*push)(int a);
    int (*pop)(void);

} queue;

int arr[queue_size];
int front = 0;
int back = -1;
int length()
{
    return back + 1;
}
int empty()
{
    if (front <= back)
    {
        return 0;
    }
    else
        return 1;
}
void push(int a)
{
    if (back < queue_size)
        arr[++back] = a;
    else
    {
        printf("queue overflowed");
    }
}
int pop()
{
    if (!empty())
    {
        front = front + 1;
        return arr[front - 1];
    }
    else
    {
        return -1;
    }
}
int head()
{
    return arr[front];
}
int tail()
{
    return arr[back];
}
void print(queue q)
{
    int counter = front;
    q.empty = empty;
    q.pop = pop;
    while (!q.empty())
    {
        printf("%d ", q.pop());
    }
    front = counter;
    endl;
}

int main()
{
    queue q;
    q.size = length;
    q.top = head;
    q.back = tail;
    q.push = push;
    q.pop = pop;
    q.empty = empty;

    for (int i = 0; i < 10; i++)
    {
        q.push(i + 1);
    }

    printf("%d %d\n", q.top(), q.back());

    int x = q.pop();
    printf("Poping: %d\n", x);
    x = q.pop();
    printf("Poping: %d\n", x);

    print(q);
    x = q.pop();
    printf("Poping: %d\n", x);
    print(q);

    return 0;
}