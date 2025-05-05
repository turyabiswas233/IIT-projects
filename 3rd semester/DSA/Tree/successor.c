#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *insert(int data, struct node *p)
{
    struct node *i = (struct node *)malloc(sizeof(struct node));
    i->data = data;
    i->left = i->right = NULL;
    i->parent = p;
    return i;
}

struct node *BST(struct node *root, int data, struct node *parent)
{
    if (root == NULL)
        return insert(data, parent);
    if (data <= root->data)
        root->left = BST(root->left, data, root);
    else
        root->right = BST(root->right, data, root);
    return root;
}

void inOrdertravarsel(struct node *root)
{
    if (root != NULL)
    {
        inOrdertravarsel(root->left);

        printf("%d ", root->data);

        inOrdertravarsel(root->right);
    }
}

struct node *maximan(struct node *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

struct node *miniman(struct node *x)
{

    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

struct node *findSuccessor(struct node *x)
{
    if (x->right != NULL)
        return miniman(x->right);
    struct node *y = x->parent;        // ekhane y te x er parent asign korlam...
    while (y != NULL && x == y->right) // erpor e 4 no line onujai y jotokkhon null na hoy && x er mane y->right er soman...
    {
        x = y;         // ekhane x = y korlam
        y = y->parent; // y er value transfer kore y.parent korlam
    }
    return y;
}

struct node *findNode(struct node *x, int data)
{
    while (x != NULL)
    {
        if (data == x->data)
            break;
        if (data <= x->data)
        {
            x = x->left;
        }
        else
            x = x->right;
    }
    return x;
}

int main()
{
    struct node *p = BST(NULL, 15, NULL);
    struct node *p1 = BST(p, 6, p);
    struct node *p2 = BST(p, 18, p);
    struct node *p3 = BST(p, 3, p);
    struct node *p4 = BST(p, 7, p);
    struct node *p5 = BST(p, 17, p);
    struct node *p6 = BST(p, 20, p);
    struct node *p7 = BST(p, 2, p);
    struct node *p8 = BST(p, 4, p);
    struct node *p9 = BST(p, 13, p);
    struct node *p10 = BST(p, 9, p);
    printf("inorder traversal:\n");
    inOrdertravarsel(p);

    struct node *tmp = findNode(p, 18);
    printf("\n%d:-\n", tmp->data);
    struct node *successor = findSuccessor(tmp);
    printf("\nthe successor of %d is %d\n", tmp->data, successor->data);

    return 0;
}