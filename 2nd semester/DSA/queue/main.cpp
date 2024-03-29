#include <bits/stdc++.h>
using namespace std;
#define range 99999
class MyQueue
{
private:
    int myqueue[range] = {0};
    int front = 0;
    int rear = -1;

public:
    bool isEmpty()
    {
        return front <= rear ? false : true;
    }
    void push(int x)
    {

        if (rear + 1 == range)
        {
            cout << "QUEUE OVERFLOWED" << endl;
        }
        else
        {
            myqueue[++rear] = x;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "QUEUE Empty!!" << endl;
        }
        else
        {
            front++;
        }
        return myqueue[front - 1];
    }
    int size()
    {
        return rear - front + 1;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    int value;
    MyQueue queues;
    cout << "What do u want? [1. push(), 2. pop()]: ";
    cin >> n;
    switch (n)
    {
    case 1:
        do
        {
            cout << "Enter positive value: ";
            cin >> value;
            if (value == -1)
                break;
            queues.push(value);
        } while (value != -1);
        break;
    case 2:
        queues.pop();
        break;

    default:
        cout << "INVALID Option\n";
        break;
    }
    while (!queues.isEmpty())
    {
        cout << queues.size() << "->" << queues.pop() << endl;
    }

    return 0;
}
