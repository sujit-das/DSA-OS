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
 * along with Moonlight; if not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

void printData(int* ai, int len);
void removeIndex(int* ai, int len, int index);
void removeDuplicate(int* ai, int* plen);

int main()
{
    int ai[] = {12,34,34,56,78,90,90,12,23,2};
    int len = sizeof(ai) / sizeof(ai[0]);

    printf("Before removal\n");
    printData(ai, len);

    removeDuplicate(ai, &len);

    printf("\nAfter removal\n");
    printData(ai, len);

    return 0;
}

void printData(int* ai, int len)
{
    for(int count=0;count<len;count++)
    {
        printf("%d ", ai[count]);
    }
}

void removeDuplicate(int* ai, int* plen)
{
    int len = *plen;
    for(int count=0; count< len; count++)
    {
        for(int count1 = count+1; count1 < len; count1++)
        {
            if( *(ai+count) == *(ai+count1) ) // duplicate found
            {
                //remove the duplicate index
                removeIndex(ai, len, count1);
                len--;
            }
        }
        
    }
    *plen = len;
}

void removeIndex(int* ai, int len, int index)
{
    for (int loop = index; loop < len -1 ; loop++)
    {
        *(ai+loop) = *(ai+loop+1);
    }
}

