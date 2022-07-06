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


