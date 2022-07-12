This is essentially a help file which includes generic and this repository specific information

# General Tips

## SSH keys creation

1. Check for existing SSH keys - cd ~/.ssh , ls -la OR ls id_*
2. Backup old keys - mkdir key_backup , cp id_rsa* key_backup
3. Generate a new key - 
   ssh-keygen -t rsa -C "to.sujitdas@gmail.com"
   no pass phrase selected / hit enter
4. cat yes.pub   / this is the public key generated, content needs to be copied and pasetd into bitbucket

## Git config

You can use the git config to enable credentials storage in git.

git config --global credential.helper store

Command to set git user name and paassword:
git config --global user.name "Sujit Das"
git config --global user.email "to.sujitdas@gmail.com"

Command to clone: git clone git@github.com:sujit-das/LibAlgo.git

## C++ source compilation

Command: c++ <file_name> 

# DSA-OS

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
              
## RemoveDuplicateInArray.c

Remove all duplicate elements from a given array

## SwapToNumbers.c

Swap two numbers without using a third variable. It implements two possible methods, one using arithmatic operator and another one using BITWISE XOR operator

