#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 100

typedef struct queue {
    int *array;
    int size;
    int front;
    int rear;
} queue;

int isEmpty(queue *q) {
    if(q->rear== q->front) return 1;
    return 0;
}

void enqueue(queue *q, int data) {
    if(q->size > q->rear){
        q->array[q->rear] = data;
        q->rear+=1;
    } else printf("Stack Overflow!\n");
}
int dequeue(queue *q) {
    if(isEmpty(q)) printf("NO DATA TO DEQUEUE!\n");
    else {
        q->front +=1;
        return q->array[q->front -1];
    }
}

int main() {
    queue *q =(queue *) malloc(sizeof(queue));
    q->size = SIZE;
    q->array = (int *)malloc(sizeof(int)*q->size);
    q->rear = 0;
    q->front = 0;
    int n,x;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    while(n < SIZE && n >0) {
        --n;
        printf("Enter value: ");
        scanf(" %d", &x);
        enqueue(q,x);
    }
    while(isEmpty(q) != 1) {
        printf("%d, ", dequeue(q));
    }

    return 0;
}
