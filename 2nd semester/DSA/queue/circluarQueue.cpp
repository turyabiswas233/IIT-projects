#include <bits/stdc++.h>

using namespace std;

class Queue
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void push(int value);
    int pop();
    void print();
};
/*Function to create Circular queue */
void Queue::push(int value)
{
    if ((front == 0 && rear == size - 1) ||
        ((rear + 1) % size == front))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::pop()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

void Queue::print()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    Queue q(6);

    // Inserting elements in Circular Queue
    q.push(14);
    q.push(22);
    q.push(13);
    q.push(-6);

    // Display elements present in Circular Queue
    q.print();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.pop());
    printf("\nDeleted value = %d", q.pop());

    q.print();

    q.push(9);
    q.push(20);
    q.push(5);

    q.print();

    q.push(20);
    q.push(4420);
    q.print();

    return 0;
}
