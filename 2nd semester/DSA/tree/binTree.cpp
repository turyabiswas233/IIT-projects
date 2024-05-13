

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *BST(struct node *, int);
struct node *newNode(int);
void minSort(struct node *p);
void maxShort(struct node *p);
int main()
{
    int data[] = {5, 9, 4, 1, 7, 3, 2, 10, 8, 6};
    struct node *p = NULL;

    for (int x : data)
    {
        p = BST(p, x);
    }

    cout << "In-order tree traverse: " << endl;
    minSort(p);
    cout << endl
         << "In-order tree traverse: " << endl;
    maxShort(p);

    return 0;
}
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *BST(struct node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (root->data > data)
        root->left = BST(root->left, data);

    else
        root->right = BST(root->right, data);
    return root;
}
void minSort(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    minSort(p->left);
    cout << p->data << " ";
    minSort(p->right);
}
void maxShort(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    maxShort(p->right);
    cout << p->data << " ";
    maxShort(p->left);
}
