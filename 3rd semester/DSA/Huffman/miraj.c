#include <stdio.h>
#include <stdlib.h>

// Creating Structure named node
typedef struct node
{
    int rollNo;
    double cgpa;
    struct node *next;
} students;

students *start = NULL;

void createList(int rollNo, double cgpa)
{
    students *newnode = malloc(sizeof(students));

    newnode->rollNo = rollNo;
    newnode->cgpa = cgpa;
    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
        return;
    }

    students *save = start;
    students *ptr = start->next;

    while (ptr != NULL)
    {
        save = ptr;
        ptr = ptr->next;
    }
    save->next = newnode;
}

void insertAtBeginning(struct node **head_ref, int rollNo, double cgpa)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->rollNo = rollNo;
    newNode->cgpa = cgpa;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void insertAtEnd(struct node **head_ref, int rollNo, double cgpa)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    newNode->rollNo = rollNo;
    newNode->cgpa = cgpa;
    newNode->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void deleteNode(struct node **head_ref, int rollNo)
{
    struct node *temp = *head_ref;
    struct node *prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->rollNo == rollNo)
    {
        *head_ref = temp->next; // Change head
        free(temp);             // Free memory
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->rollNo != rollNo)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the node with the given rollNo was not found
    if (temp == NULL)
    {
        printf("Node with rollNo %d not found.\n", rollNo);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

students *searchByRollNo(int rollNo)
{
    students *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->rollNo == rollNo)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void printLinkedList()
{
    students *ptr = start;
    while (ptr != NULL)
    {
        printf("%d %lf\n", ptr->rollNo, ptr->cgpa);
        ptr = ptr->next;
    }
}

void sortLinkedList(struct node **head_ref)
{
    struct node *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL)
    {
        return;
    }

    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->rollNo > index->rollNo)
                {
                    temp = current->rollNo;
                    current->rollNo = index->rollNo;
                    index->rollNo = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int main()
{

    int n;
    int rollNo;
    double cgpa;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %lf", &rollNo, &cgpa);
        createList(rollNo, cgpa);
    }

    printf("Linked list after creation:\n");
    printLinkedList();

    // Insert data at the beginning
    insertAtBeginning(&start, 1, 3.98);
    printf("Linked list after inserting rollNo 1, cgpa 3.98 at the beginning: \n");
    printLinkedList();

    // Insert at the end
    insertAtEnd(&start, 6, 3.6);
    printf("Linked list after inserting rollNo 6, cgpa 3.6 at the end: \n");
    printLinkedList();

    deleteNode(&start, 4);
    printf("Linked list after deleting data of roll no 4: \n");
    printLinkedList();

    sortLinkedList(&start);
    printf("Linked list after sorting:\n");
    printLinkedList();

    // students *result = searchByRollNo(4);
    // printf("\nCGPA of roll 4 is : %lf\n\n", result->cgpa);
    // printLinkedList();
}
