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

void swapArithmatic (int *pa1, int *pa2);
void swapXor (int *pa1, int *pa2);

int main ()
{
  int a1 = -12, a2 = -34;
  printf ("Before swap\n");
  printf ("Numbers: %d, %d", a1, a2);
  swapArithmatic (&a1, &a2);
  printf ("\nAfter swap\n");
  printf ("Numbers: %d, %d", a1, a2);
  swapXor (&a1, &a2);
  printf ("\nAfter swap\n");
  printf ("Numbers: %d, %d", a1, a2);
  return 0;
}

void swapArithmatic (int *pa1, int *pa2)
{
  *pa1 = *pa1 - *pa2;
  *pa2 = *pa1 + *pa2;
  *pa1 = *pa2 - *pa1;
}

void swapXor (int *pa1, int *pa2)
{
  *pa1 = *pa1 ^ *pa2;
  *pa2 = *pa1 ^ *pa2;
  *pa1 = *pa1 ^ *pa2;
}


