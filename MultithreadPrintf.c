/*
 * Copyright (C) 2022 Sujit Das
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, see <http://www.gnu.org/licenses/>.
 */
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
