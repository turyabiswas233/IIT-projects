#include <stdio.h>
#include <stdlib.h>

typedef struct Task
{
    char *taskName;
    int priority;
    int cpuBurst;
    int startTime;
    int finishTime;
} Task;

int main(int argc, char const *argv[])
{
    int n;
    scanf(" %d", &n);
    int chunk = 100000000;
    Task *tasks = (Task *)malloc(sizeof(Task) * n);
    for (size_t i = 0; i < n; i++)
    {
        Task *n = (Task *)malloc(sizeof(Task));
        scanf(" %s %d %d", n->taskName, n->priority, n->cpuBurst);
        n->startTime = n->finishTime = 0;
        tasks[i] = *n;
        chunk = (chunk > n->cpuBurst ? n->cpuBurst : chunk);
    }
    chunk = (chunk / 2 > 0 ? chunk / 2 : 1);
    for (size_t x = 0; x < n; x++)
    {
        printf("TaskName: %s [%d %d]\n", tasks[x].taskName, tasks[x].priority, tasks[x].cpuBurst);
    }

    return 0;
}
