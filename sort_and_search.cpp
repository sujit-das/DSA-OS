#include<stdio.h>

#define LENGTH_OF_ARRAY(array) (sizeof(array)/sizeof(array[0])) 

int bubble_sort(int* pData, unsigned int len);
int binary_search(int key, int* pData, unsigned int start_index, unsigned int end_index);

main()
{
    int* data1 = NULL;
    int  data2[] = {12};
    int  data3[] = {12,34,56,78,90, 123, 234, 345, 456, 678, 789, 890, 901};
    int  data4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // Test bubble sort
    printf("Sort 1 result: %d\n", bubble_sort(data1,3));
    printf("Sort 2 result: %d\n", bubble_sort(data2,0));
    printf("Sort 3 result: %d\n", bubble_sort(data2,1));

    printf("Sort 4 result: %d\n", bubble_sort(data3,LENGTH_OF_ARRAY(data3)));
    for(int count = 0; count < LENGTH_OF_ARRAY(data3);count++)
        printf("%d\n", *(data3+count));

    printf("Sort 5 result: %d\n", bubble_sort(data4,LENGTH_OF_ARRAY(data4)));
    for(int count = 0; count < LENGTH_OF_ARRAY(data4);count++)
        printf("%d\n", *(data4+count));

    // Test binary search
    printf("Search 1 result: %d\n", binary_search(12, data1, 1, 2));
    printf("Search 2 result: %d\n", binary_search(12, data2, 0, 0));
    printf("Search 3 result: %d\n", binary_search(21, data2, 0, 0));
    printf("Search 4 result: %d\n", binary_search(56, data3, 3, 3));
    printf("Search 5 result: %d\n", binary_search(78, data3, 3, 3));
    printf("Search 6 result: %d\n", binary_search(34, data3, 0, 3));
    printf("Search 7 result: %d\n", binary_search(34, data3, 0, 4));
    printf("Search 8 result: %d\n", binary_search(3, data3, 0, 4));
    printf("Search 9 result: %d\n", binary_search(134, data3, 0, 4));
    printf("Search 10 result: %d\n", binary_search(12, data3, 0, LENGTH_OF_ARRAY(data3)-1 ));
    printf("Search 11 result: %d\n", binary_search(901, data3, 0, LENGTH_OF_ARRAY(data3)-1 ));
    printf("Search 12 result: %d\n", binary_search(901, data3, 12, 0));

    return 0;
}

int bubble_sort(int* pData, unsigned int len)
{
    int result = -1;

    if(pData != NULL) 
    {
        if(len == 0) 
        {
            // Do nothing
        }
        else if(len == 1)
            result = 1;
        else
        {   
            for(unsigned int passCounter = 1; passCounter <= len-1; passCounter++ )
            {
                for(unsigned int inerLoopCounter = 1; inerLoopCounter <= (len - passCounter); inerLoopCounter++ )
                {
                    if(*(pData+inerLoopCounter-1) > *(pData+inerLoopCounter)) 
                    {
                        // swap
                        int temp = *(pData+inerLoopCounter-1);
                        *(pData+inerLoopCounter-1) = *(pData+inerLoopCounter);
                        *(pData+inerLoopCounter) = temp; 
                    }
                }
            }
            result = 1;
        }
    }
    else
        printf("Invalid argument\n");

    return result;
}

int binary_search(int key, int* pData, unsigned int start_index, unsigned int end_index)
{
    int loc = -1;

    if(pData == NULL || start_index > end_index) 
    {
        printf("Invalid argument\n");
        return loc;
    }
    else if(start_index == end_index)
    {
        if(*(pData + start_index) == key)
            loc = start_index;
        return loc;
    }
    else
    {
        int mid = (start_index + end_index) / 2;
        if(key <= *(pData+mid))
            binary_search(key, pData, start_index, mid);
        else
            binary_search(key, pData, mid+1, end_index);
    }
}
