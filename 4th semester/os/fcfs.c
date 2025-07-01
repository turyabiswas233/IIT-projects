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
void printTask(Task t)
{
       printf("%s\t: %02d ms %02d ms {%02d | %02d}\n", t.taskName, t.startTime, t.finishTime, t.priority, t.cpuBurst);

}
int main(int argc, char const *argv[])
{
    int n;
    scanf(" %d", &n);
    Task *tasks = (Task *)malloc(sizeof(Task) * n);
    for (size_t i = 0; i < n; i++)
    {
        Task *n = (Task *)malloc(sizeof(Task));
        n->taskName = (char *)malloc(sizeof(char) * 10);
        scanf(" %s %d %d", n->taskName, &n->priority, &n->cpuBurst);
        n->startTime = n->finishTime = 0;
        tasks[i] = *n;
    }
    int totalTime = 0, avgWT = 0;
    for (size_t i = 0; i < n; i++)
    {
        totalTime += tasks[i].cpuBurst;
        if (i == 0)
        {
            tasks[i].startTime = 0;
            tasks[i].finishTime = tasks[i].cpuBurst;
        }
        else
        {
            tasks[i].startTime = tasks[i - 1].finishTime;
            tasks[i].finishTime = tasks[i].startTime + tasks[i].cpuBurst;
        }
        avgWT += tasks[i].startTime;
    }

    for (size_t i = 0; i < n; i++)
    {
        printTask(tasks[i]);
    }
    printf("Average wating time: %0d ms\n", avgWT/n);

    return 0;
}
