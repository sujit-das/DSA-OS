#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* threadEntry1(void* arg1);
void* threadEntry2(void* arg2);

sem_t thread_sem1;
sem_t thread_sem2;

int main()
{
    pthread_t thread_id1, thread_id2;
    int data1 = 100, data2=200;
    sem_init(&thread_sem1,0,1);
    sem_init(&thread_sem2,0,0);

    pthread_create(&thread_id1, NULL, threadEntry1, &data1);
    pthread_create(&thread_id2, NULL, threadEntry2, &data2);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    sem_destroy(&thread_sem1);
    sem_destroy(&thread_sem2);

    return 0;
}

void* threadEntry1(void* arg1)
{
    int* pint1 = (int*)arg1;
    while(*pint1 < 199)
    {
        sem_wait(&thread_sem1);
        printf("%d\n", (*pint1)++);
        sem_post(&thread_sem2);
    }
}

void* threadEntry2(void* arg2)
{
    int* pint2 = (int*)arg2;
    while(*pint2 < 299)
    {
        sem_wait(&thread_sem2);
        printf("%d\n", (*pint2)++);
        sem_post(&thread_sem1);
    }
}
