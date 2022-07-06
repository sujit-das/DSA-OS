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
