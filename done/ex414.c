#include <stdio.h>

#define swap(t, x, y) t z = x ; x = y ; y = z

int main (void)
{
    int a = 1;
    int b = 2;
    swap(int, a, b);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
