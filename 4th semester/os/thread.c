#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// Function to be executed by the thread
void * runner(void *arg){
    printf("Thread %d is running\n", (int)arg);
    return NULL;
}
int main(int argc, char *argv[])
{
    int x = (int)atoi(argv[1]);
    if (argc != 2)
    {
        perror("Usage: ./thread <number>");
        return EXIT_FAILURE;
    }
    pthread_t *thread;
    pthread_attr_t *attr;
    thread = (pthread_t *)malloc(sizeof(pthread_t));
    attr = (pthread_attr_t *)malloc(sizeof(pthread_attr_t));
    if (thread == NULL || attr == NULL){
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    for(int i = 1; i <= x; i++)
    {
        if (pthread_create(thread, attr, runner, (void *)i) != 0)
        {
            perror("Thread creation failed");
            free(thread);
            free(attr);
            return EXIT_FAILURE;
        }
        else {
            printf("Thread %d created\n", i);
        }
        pthread_join(*thread, NULL);
    }
    printf("Thread has finished\n");
    free(thread);
    free(attr);
    return EXIT_SUCCESS;
}