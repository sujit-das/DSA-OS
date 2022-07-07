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

void func(int* p)
{
    static int r = 20;
    p = &r;
    return;
}

int main()
{
    int i = 5;
    int *j;
    
    printf("Hello World\n");
    printf("i = %d\n", i);
    func(&i);
    printf("i = %d\n", i);
    printf("j = %d\n", *j);

    return 0;
}
