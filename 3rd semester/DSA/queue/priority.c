#include <stdio.h>
#include <stdlib.h>
#define type int

typedef struct node {
    type info;
    int PRN;
    struct node *next;
} node;

node *createNode(type a,int PRN) {
    node *temp = (node *)malloc(sizeof(node));
    temp->info = a;
    temp->PRN = PRN;
    temp->next = NULL;
    return temp;
}
void createList(node *head){
    printf("Enter info and priority: ");
    type inf;
    int prn;
    if(sizeof(type) == sizeof(char))
        scanf(" %c", &inf);
    else if(sizeof(type) == sizeof(int))
        scanf(" %d", &inf);
    scanf(" %d", &prn);
    if(prn< 0) {
        printf("##\tINVALID PRIORITY\t##\n");
        return;
    }
    node *newNode = createNode(inf,prn);
    if(head==NULL){
        head = newNode;
        printf("root...\n");
        return;
    }
    // now add data according to priority...
    node *save = head;
    node *ptr = head->next;
    while(ptr != NULL){
        printf("inside loop...\n");
        if(ptr->PRN == prn) {
            newNode->next=ptr->next;
            ptr->next = newNode;
            return;
        }
        else if(ptr->PRN < prn) {
            newNode->next = ptr;
            save->next = newNode;
            return;
        }
        else
            ptr = ptr->next;
    }
    save->next = newNode;
}

int main() {
    node *head=NULL;
    int n;
    printf("Enter data number: ");
    scanf("%d", &n);
    while(n--) {
        createList(head);
    }
    node *tmp = head;
    while(tmp != NULL) {
        printf("%d %c\n", tmp->PRN, tmp->info);
        tmp = tmp->next;
    }
    return 0;
}
