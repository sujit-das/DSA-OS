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
#include <iostream>
#include <pthread.h>
#include <queue>
#include <stdlib.h>
 
#define MAX1 5     // size of the queue
#define MAX2 1000  // maximum number of itertaion allowed in app

 
using namespace std;
 
// Declaring global variables
int sum_B = 0, sum_C = 0;
int consumerCount1 = 0;
int consumerCount2 = 0;
 
// Shared queue
queue<int> Q;
 
// Function declaration of all required functions
void* producerFun(void*);
void* add_B(void*);
void* add_C(void*);
 
// Getting the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 
pthread_cond_t dataNotProduced =
                    PTHREAD_COND_INITIALIZER;
pthread_cond_t dataNotConsumed =
                    PTHREAD_COND_INITIALIZER;
 
// Function to generate random numbers and
// push them into queue using thread A
 
void* producerFun(void*)
{
    static int producerCount = 0;
     
    // Initialising the seed
    srand(time(NULL));
     
    while (1) {
        // Getting the lock on queue using mutex
        pthread_mutex_lock(&mutex);
 
        if (Q.size() < MAX1 && producerCount < MAX2)
        {
             
            // Getting the random number
            int num = rand() % 10 + 1;
            cout << "Produced:  " << num << endl;
 
            // Pushing the number into queue
            Q.push(num);
 
            producerCount++;
 
            pthread_cond_broadcast(&dataNotProduced);
        }
 
        // If queue is full, release the lock and return
        else if (producerCount == MAX2) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
 
        // If some other thread is executing, wait
        else {
            cout << ">> Producer is in wait.." << endl;
            pthread_cond_wait(&dataNotConsumed, &mutex);
        }
 
        // Get the mutex unlocked
        pthread_mutex_unlock(&mutex);
    }
}
 
// Function definition for consumer thread B
void* add_B(void*)
{
     while (1) {
 
        // Getting the lock on queue using mutex
        pthread_mutex_lock(&mutex);
 
        // Pop only when queue has at least 1 element
        if (Q.size() > 0) {
            // Get the data from the front of queue
            int data = Q.front();
 
            cout << "B thread consumed: " << data << endl;
 
            // Add the data to the integer variable
            // associated with thread B
            sum_B += data;
 
            // Pop the consumed data from queue
            Q.pop();
 
            consumerCount1++;
 
            pthread_cond_signal(&dataNotConsumed);
        }
 
        // Check if consumed numbers from both threads
        // has reached to MAX value
        else if (consumerCount2 + consumerCount1 == MAX2) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
 
        // If some other thread is executing, wait
        else {
            cout << "B is in wait.." << endl;
            pthread_cond_wait(&dataNotProduced, &mutex);
        }
 
        // Get the mutex unlocked
        pthread_mutex_unlock(&mutex);
    }
}
 
// Function definition for consumer thread C
void* add_C(void*)
{
    while (1) {
 
        // Getting the lock on queue using mutex
        pthread_mutex_lock(&mutex);
 
        // Pop only when queue has at least 1 element
        if (Q.size() > 0) {
 
            // Get the data from the front of queue
            int data = Q.front();
            cout << "C thread consumed: " << data << endl;
 
            // Add the data to the integer variable
            // associated with thread B
            sum_C += data;
 
            // Pop the consumed data from queue
            Q.pop();
            consumerCount2++;
 
            pthread_cond_signal(&dataNotConsumed);
        }
 
        // Check if consumed numbers from both threads
        // has reached to MAX value
        else if (consumerCount2 + consumerCount1 == MAX2)
        {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
 
        // If some other thread is executing, wait
        else {
            cout << ">> C is in wait.." << endl;
            // Wait on a condition
            pthread_cond_wait(&dataNotProduced, &mutex);
        }
 
        // Get the mutex unlocked
        pthread_mutex_unlock(&mutex);
    }
}
 
// Driver code
int main()
{
    // Declaring integers used to
    // identify the thread in the system
    pthread_t producerThread, consumerThread1, consumerThread2;
 
    // Function to create a threads
    // (pthread_create() takes 4 arguments)
    int retProducer = pthread_create(&producerThread,
                      NULL, producerFun, NULL);
    int retConsumer1 = pthread_create(&consumerThread1,
                       NULL, *add_B, NULL);
    int retConsumer2 = pthread_create(&consumerThread2,
                       NULL, *add_C, NULL);
 
    // pthread_join suspends execution of the calling
    // thread until the target thread terminates
    if (!retProducer)
        pthread_join(producerThread, NULL);
    if (!retConsumer1)
        pthread_join(consumerThread1, NULL);
    if (!retConsumer2)
        pthread_join(consumerThread2, NULL);
 
    // Checking for the final value of thread
    if (sum_C > sum_B)
        cout << "Winner is  Thread C" << endl;
    else if (sum_C < sum_B)
        cout << "Winner is  Thread B" << endl;
    else
        cout << "Both has same score" << endl;
     
    return 0;
}
