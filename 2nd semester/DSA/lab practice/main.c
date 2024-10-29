#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void infixToPostfix(char *infix, char *postfix);
void solvePostfix(char *postfix);
int main(int argc, char const *argv[])
{
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    // now calculate the postfix expression
    solvePostfix(postfix);
    return 0;
}

void infixToPostfix(char *infix, char *postfix)
{
    int stack[100], top = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            stack[++top] = '(';
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (infix[i] == '+' || infix[i] == '-')
            {
                while (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')
                {
                    postfix[j++] = stack[top--];
                }
            }
            else if (infix[i] == '*' || infix[i] == '/')
            {
                while (stack[top] == '*' || stack[top] == '/')
                {
                    postfix[j++] = stack[top--];
                }
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[j++] = infix[i];
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("The postfix expression is: %s\n", postfix);
}

void solvePostfix(char *postfix)
{
    int stack2[100], top2 = -1;
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int a = stack2[top2--];
            int b = stack2[top2--];
            if (postfix[i] == '+')
            {
                stack2[++top2] = a + b;
            }
            else if (postfix[i] == '-')
            {
                stack2[++top2] = b - a;
            }
            else if (postfix[i] == '*')
            {
                stack2[++top2] = a * b;
            }
            else if (postfix[i] == '/')
            {
                stack2[++top2] = b / a;
            }
        }
        else
        {
            stack2[++top2] = postfix[i] - '0';
        }
        i++;
    }
    printf("The result is: %d\n", stack2[top2]);
}