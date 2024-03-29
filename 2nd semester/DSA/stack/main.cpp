#include <bits/stdc++.h>
using namespace std;
#define range 99999

class MyStack
{

private:
    int mystack[range] = {0};
    int front = 0;
    int rear = -1;

public:
    bool isEmpty()
    {
        return rear >= 0 ? false : true;
    }
    void push(int x)
    {

        if (rear + 1 == range)
        {
            cout << "Stack OVERFLOWED" << endl;
        }
        else
        {
            mystack[++rear] = x;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack UNDERFLOWED" << endl;
        }
        else
        {
            rear--;
        }
        return mystack[rear + 1];
    }
};

int main()
{
    int n;
    int value;
    MyStack stacks;
    stack<int> x;
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
            stacks.push(value);
        } while (value != -1);
        break;
    case 2:
        stacks.pop();
        break;

    default:
        cout << "INVALID Option\n";
        break;
    }

    while (!stacks.isEmpty())
    {
        cout << stacks.pop() << " ";
    }
}
