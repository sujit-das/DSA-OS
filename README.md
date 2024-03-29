This is essentially a help file which includes generic and this repository specific information

# General Tips

## C++ source compilation

Command: c++ <file_name>

## Git config

You can use the git config to enable credentials storage in git.

git config --global credential.helper store

Command to set git user name and paassword:
git config --global user.name "Sujit Das"
git config --global user.email "to.sujitdas@gmail.com"

Command to clone: git clone git@github.com:sujit-das/LibAlgo.git

## SSH keys creation

1. Check for existing SSH keys - cd ~/.ssh , ls -la OR ls id_*
2. Backup old keys - mkdir key_backup , cp id_rsa* key_backup
3. Generate a new key - 
   ssh-keygen -t rsa -C "to.sujitdas@gmail.com"
   no pass phrase selected / hit enter
4. cat yes.pub   / this is the public key generated, content needs to be copied and pasetd into bitbucket
 
# DSA-OS

## CppVersion.cpp

Demonstrates the usage of compiler defined macros to retrieve the version of cpp compiler version



<script src="https://platform.linkedin.com/badges/js/profile.js" async defer type="text/javascript"></script>

<div class="badge-base LI-profile-badge" data-locale="en_US" data-size="large" data-theme="dark" data-type="HORIZONTAL" data-vanity="sujitd" data-version="v1"><a class="badge-base__link LI-simple-link" href="https://in.linkedin.com/in/sujitd?trk=profile-badge">Sujit Das</a></div>
              
## Graph.cpp

This implements graph initilization using adjacency matrix, BFS and DFS traversal

## HCFandLCM.cpp

This program implements two methods, one to compute Highest Common Factor and another one to compute Lowest Common Multiple.

## Learn.c

Demonstrates the scope and life time of a static variable

## MultithreadPrintf.c

This program prints numbers from two different threads in such a way that one print from a thread will always be followed by a print from the another thread.
That means no consecutive prints will be from the same thread.
Sample o/p => 100
              200
              101
              201
              102
              202
              103
              203
              ...
              , where numbers of 100 range get printed from one thread and numbers of 200 range get printed from the other thread.

## MultithreadPrintf.cpp

Functionality wise, this program does not differ from its c version. But this program demonstrates synchronization between multiple thereads

## ProducerConsumer.cpp

This program simulates producer-consumer problem in multithreaded environment. It has one producer thread and two consumer threads and it uses mutex for synchronization between thse threads.
              
## RemoveDuplicateInArray.c

This program removes all duplicate elements from a given array

## SinglyLinkedListRoutines.cpp

This program implements few general routines of a singly linked lists, namely methods to insert in the beginning, insert at the end, delete the current node, delete the last node, delete next node, print a linked list, find the middle node of a linked list, search an item in the list, delete an item from the list, sort a linked list etc.

## SortAndSearch.c

Implements recursive and iterative method for binary serach in an array, bubble sort in an arry

## SortAndSearch.cpp

This is nothing distinguishinbgly special from SortAndSearch.c. This also implements bubble sort and recursive version of binary search in an array.

## StackUsingLinkedList.cpp

This program implements a stack using linkedlist to store data elements. It implements stack creation, push and pop operations

## SwapToNumbers.c

This program swaps two numbers without using a third variable. It implements two possible methods, one using arithmatic operator and another one using BITWISE XOR operator





<script src="https://platform.linkedin.com/badges/js/profile.js" async defer type="text/javascript"></script>

<div class="badge-base LI-profile-badge" data-locale="en_US" data-size="large" data-theme="dark" data-type="HORIZONTAL" data-vanity="sujitd" data-version="v1"><a class="badge-base__link LI-simple-link" href="https://in.linkedin.com/in/sujitd?trk=profile-badge">Sujit Das</a></div>

