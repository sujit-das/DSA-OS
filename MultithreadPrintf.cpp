/*
 *
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
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
    private:
        mutex _mutex;
        condition_variable _conditionVariable;
        int _count;

    public:
        Semaphore(int count = 0)
        {
            _count = count;
        }

        void acquire()
        {
            unique_lock<decltype(_mutex)> lockMutex(_mutex);
            while(!_count)
                _conditionVariable.wait(lockMutex);
            _count--;
        }

        bool tryAcquire()
        {
            bool result = false;
            if(_count)
            {
                _count--;
                result = true;
            }
            return result;
        }

        void release()
        {
            lock_guard<decltype(_mutex)> lockMutex(_mutex);
            _count++;
            _conditionVariable.notify_one();
        }
};

void threadEntry1(int* arg1);
void threadEntry2(int* arg2);

Semaphore threadSem1(1);
Semaphore threadSem2(0);

int main()
{
    int data1 = 100, data2=200;

    thread  threadId1(threadEntry1, &data1);
    thread  threadId2(threadEntry2, &data2);
    
    threadId1.join();
    threadId2.join();

    cout << "From main " << data1 << " " << data2 << endl;
    return 0;
}

void threadEntry1(int* arg1)
{
    while(*arg1 < 199)
    {
        threadSem1.acquire();
        cout <<  *arg1 << endl;
        (*arg1)++;
        threadSem2.release();
    }
}

void threadEntry2(int* arg2)
{
    while(*arg2 < 299)
    {
        threadSem2.acquire();
        cout <<  *arg2 << endl;
        (*arg2)++;
        threadSem1.release();
    }
}






