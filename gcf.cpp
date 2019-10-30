#include<stdio.h>

inline Mod(unsigned int arg1, unsigned int arg2)
{
	return (arg1 % arg2);
}
int gcf(int, int);
int main(void)
{
   printf("%d\n", Mod(12, 34));
   printf("%d\n", Mod(34, 12));
   printf("%d\n", gcf(12, 34));
   printf("%d\n", gcf(34, 12));
}

int gcf(int arg1, int arg2)
{
	int mod12 = Mod(arg1, arg2);
	if( 0 == mod12 )
		return arg2;
	else
		gcf(arg2, mod12 );
}
