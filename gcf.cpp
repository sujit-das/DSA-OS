#include<stdio.h>

int gcf(int, int);
int main(void)
{
   printf("%d\n", gcf(12, 34));
   printf("%d\n", gcf(34, 12));
}

int gcf(int arg1, int arg2)
{
	int mod = arg1 % arg2;
	if( 0 == mod )
		return arg2;
	else
		gcf(arg2, mod );
}
