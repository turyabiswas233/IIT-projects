#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack
{
    int top;
    char *items;
};
struct stackInt
{
    int top;
    int *items;
};

void initStack(struct stack *s)
{
    s->items = (char *)malloc(MAX_SIZE * sizeof(char));
    s->top = -1;
}
void initStackInt(struct stackInt *s)
{
    s->items = (int *)malloc(MAX_SIZE * sizeof(int));
    s->top = -1;
}

bool isEmpty(struct stack *s)
{
    return s->top == -1;
}

bool isFull(struct stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(struct stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = value;
}
void pushInt(struct stackInt *s, int value)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("StackInt is full\n");
        return;
    }
    s->items[++s->top] = value;
}
char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[s->top--];
}
int popInt(struct stackInt *s, int line)
{
    if (s->top == -1)
    {
        printf("Stack is empty at: %d\n", line);
        return 0;
    }
    return s->items[s->top--];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}
bool isDigit(int x)
{
    return x >= 0 && x <= 9;
}
void infixToPostfix(char *infix, char *postfix);
int solve(char *postfix);
int main(int argc, char const *argv[])
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    infix[0] = postfix[0] = '\0';
    printf("Enter the infix expression: ");
    // scanf(" %s", infix);
    strcpy(infix, "2 + 3 + (5 + 7) / 2 + 10\0");

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Solve: %d\n", solve(postfix));
    return 0;
}
void infixToPostfix(char *infix, char *postfix)
{
    struct stack s;
    initStack(&s);
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        char x = infix[i];
        if (x == '(')
        {
            push(&s, x);
        }
        else if (x == ')')
        {
            while (!isEmpty(&s) && s.items[s.top] != '(')
                postfix[j++] = pop(&s);

            pop(&s);
        }
        else if (precedence(x) == 1 || precedence(x) == 2)
        {
            while (!isEmpty(&s) && precedence(s.items[s.top]) >= precedence(x))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, x);
        }
        else
        {
            postfix[j++] = x;
        }
        i++;
    }
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int solve(char *postfix)
{
    struct stackInt s;
    initStackInt(&s);
    int i = 0;
    int op1, op2, res;
    res = 0;
    while (postfix[i] != '\0')
    {
        char x = postfix[i];
        if (isDigit(x - '0'))
        {
            int num = 0;
            while (isDigit(postfix[i] - '0'))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushInt(&s, num);
            pushInt(&s, x - '0');
        }
        else
        {
            i++;
            op2 = popInt(&s,175);
            op1 = popInt(&s, 176);

            switch (x)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;

            default:

                break;
            }
            printf("%d, ", res);
            pushInt(&s, res);
        }
    }
    return popInt(&s,201);
}