#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum
{
    READY,
    RUNNING,
    COMPLETED
} TaskStatus;
typedef struct Task
{
    char *taskName;
    int priority;
    int cpuBurst;
    int startTime;
    int finishTime;
    int remainTime;
    TaskStatus status;
} Task;

void printTask(Task t)
{
    printf("%s\t: %02d ms %02d ms {%02d | %02d}\n", t.taskName, t.startTime, t.finishTime, t.priority, t.cpuBurst);
}
int isCompletedTasks(Task *tasks, int n)
{
    int flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (tasks[i].status != COMPLETED)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf(" %d", &n);
    int chunk = 2;
    Task *tasks = (Task *)malloc(sizeof(Task) * n);

    // take input of tasks schedules
    for (size_t i = 0; i < n; i++)
    {
        Task n = *(Task *)malloc(sizeof(Task));

        n.taskName = (char *)malloc(sizeof(char) * 10);
        scanf(" %s %d %d", n.taskName, &n.priority, &n.cpuBurst);
        n.startTime = n.finishTime = n.remainTime = 0;
        n.status = READY;
        tasks[i] = n;
    }
    chunk = (chunk / 2 > 0 ? chunk / 2 + 1 : 1);
    unsigned int totalTime = 0, avgWT = 0;
    int currentTid = 0;
    int completedTask = 0;

    Task *preTask = NULL;
    while (completedTask < n)
    {
        int orgCurrentTid = currentTid;
        while (tasks[currentTid].status == COMPLETED)
        {
            currentTid = (currentTid + 1) % n;
            if (currentTid == orgCurrentTid)
            {
                break;
            }
        }

        if (tasks[currentTid].status == COMPLETED)
        {
            break;
        }

        Task *c = &tasks[currentTid];

        c->status = RUNNING;
        int timeSliceUsed = 0;
        if (c->remainTime > chunk)
        {
            timeSliceUsed = chunk;
            c->remainTime -= chunk;
        }
        else
        {
            timeSliceUsed = c->remainTime;
            c->remainTime = 0;
            c->status = COMPLETED;
            c->finishTime = totalTime;
            completedTask++;
        }
        totalTime += timeSliceUsed;
        currentTid = (currentTid + 1) % n;
    }

    for (size_t i = 0; i < n; i++)
    {
        printTask(tasks[i]);
    }
    printf("Average waiting time: %0d ms\n", avgWT / n);
    printf("CHUNK SIZE[rr]: %0d ms\n", chunk);

    return 0;
}
