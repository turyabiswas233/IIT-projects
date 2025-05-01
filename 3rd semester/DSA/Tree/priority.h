
#define string char *

typedef struct node
{
    string data;
    int priority;
} node;

typedef struct queue
{
    node **arr;
    int SIZE;
    int front;
    int rear;
} queue;

int isEmpty(queue *);
void initQueue(queue *, int);
void push(queue *, node *);
int partition(node **, int, int);
void quickSort(node **, int, int);
void resetQueue(queue *);
node *createNode(string, int);
node *pop(queue *);

node *createNode(string data, int priority)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}
int isEmpty(queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}
void initQueue(queue *q, int size)
{

    q->SIZE = size;
    q->front = 0;
    q->rear = 0;
    q->arr = malloc(sizeof(node) * size);
}
void push(queue *q, node *n)
{
    if (q->SIZE == q->rear)
        return;
    q->arr[q->rear] = n;
    q->rear = q->rear + 1;
}
node *pop(queue *q)
{
    if (isEmpty(q))
    {
        exit(EXIT_FAILURE);
    }
    q->front = q->front + 1;
    return q->arr[q->front - 1];
}

int partition(node **arr, int low, int high)
{
    int pivot = arr[high]->priority;
    int i = low - 1;

    node *temp;
    for (int j = low; j < high; j++)
    {
        if (arr[j]->priority < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quickSort(node **arr, int low, int high)
{
    if (low < high)
    {
        int pivID = partition(arr, low, high);
        quickSort(arr, low, pivID - 1);
        quickSort(arr, pivID + 1, high);
        printf("sorted\n");
    }
}

void resetQueue(queue *q)
{
    q->front = 0;
}