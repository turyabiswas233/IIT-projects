#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int roll;
    float cgpa;
    struct node *next;

} students;
students *start = NULL;
void createNode(int roll, float cgpa)
{
    students *newNode = (students *)malloc(sizeof(students));
    newNode->roll = roll;
    newNode->cgpa = cgpa;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        return;
    }

    students *temp = start;
    students *ptr = temp;

    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = newNode;
    return;
}
void printList()
{
    students *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->roll << ", " << ptr->cgpa << endl;
        ptr = ptr->next;
    }
}
int main(int argc, char *argv[])
{
    int n;
    freopen(argv[1], "r", stdin);
    cin >> n;
    cout << "Enter " << n << " elements {roll, cgpa[0.00 - 4.00]}\n";
    int roll;
    float cgpa;
    while (n--)
    {
        cin >> roll >> cgpa;
        createNode(roll, cgpa);
    }

    printList();
}
