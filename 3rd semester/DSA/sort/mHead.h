#include <stdio.h>
#include <stdlib.h>

#define string char *

typedef struct node
{
    int age;
    string str;
    struct node *next;
} node;

typedef struct tree
{
    node *N;
    struct tree *left;
    struct tree *right;
} tree;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->age = data;
    newnode->str = (char *)malloc(sizeof(char));

    newnode->str = "turya";
    newnode->next = NULL;
    return newnode;
}
tree *createBst(tree *root, node *head)
{
    if (root == NULL)
    {
        tree *r = (tree *)malloc(sizeof(tree));
        r->N = head;
        r->left = r->right = NULL;

        return r;
    }
    else if (root->N->age >= head->age)
    {
        root->left = createBst(root->left, head);
    }
    else if (root->N->age < head->age)
    {
        root->right = createBst(root->right, head);
    }
    return root;
}

void inorder(tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("{\n  Age: %5d,\n  Name: %s\n},\n", root->N->age, root->N->str);
    inorder(root->right);
}
