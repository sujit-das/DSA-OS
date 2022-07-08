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

void printData(const int* ai, int len);
void swapXor (int *pa1, int *pa2);
void bubbleSortAsc(int* ai, int len);
int binarySearchRec(int* ai, int start_index, int end_index, int item);
int binarySearchIter(int* ai, int start_index, int end_index, int item);

int main()
{
    int ai[] = {12,34,34,56,78,90,90,12,23,2,90};
    int len = sizeof(ai) / sizeof(ai[0]);
    int item = 0, loc = -1;

    printf("Before sort\n");
    printData(ai, len);
    bubbleSortAsc(ai, len);
    printf("\nAfter sort\n");
    printData(ai, len);

    printf("\n Search Item: ");
    scanf("%d", &item);
    loc = binarySearchIter(ai, 0, len-1, item);
    printf("\n Item location: %d\n", loc);
    return 0;
}

void printData(const int* ai, int len)
{
    for(int count=0;count<len;count++)
    {
        printf("%d ", ai[count]);
    }
}

void swapXor (int *pa1, int *pa2)
{
  *pa1 = *pa1 ^ *pa2;
  *pa2 = *pa1 ^ *pa2;
  *pa1 = *pa1 ^ *pa2;
}

void bubbleSortAsc(int* ai, int len)
{
    for(int i=0; i< len - 1; i++)
    {
        for(int j=i+1; j < len; j++)
        {
            if(ai[i] > ai[j])
            {
                swapXor(ai + i, ai + j);
            }
        }
    }
}

int binarySearchRec(int* ai, int start_index, int end_index, int item)
{
    int mid_index = ( start_index + end_index ) / 2;

    //Debug print
    printf("PASS - start: %d, end: %d \n", start_index, end_index);

    if( *(ai+mid_index) == item)
        return mid_index;
    else if(item < *(ai+mid_index) && start_index < mid_index)
        return binarySearchRec(ai, start_index, mid_index -1, item);
    else if (item > *(ai+mid_index) && mid_index < end_index )
        return binarySearchRec(ai, mid_index + 1, end_index, item);
    else
        return -1;
}

int binarySearchIter(int* ai, int start_index, int end_index, int item)
{
    int loc = -1;
    int mid_index = ( start_index + end_index ) / 2;

    while((*(ai+mid_index) != item) && start_index < end_index )
    {
        if(item < *(ai+mid_index))
            end_index = mid_index -1;
        else if (item > *(ai+mid_index))
            start_index = mid_index + 1;
    
        mid_index = ( start_index + end_index ) / 2;

         //Debug print
        printf("PASS - start: %d, end: %d \n", start_index, end_index);

    }

    if(*(ai+mid_index) == item)
        loc = mid_index;

    return loc;
}
