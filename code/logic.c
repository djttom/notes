#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x = 13;

    printf("before: x is %d\n", x);
    x = x == x;
    printf("after: x is %d\n", x);

    printf("\n");
    printf("true is %d, false is %d\n", true, false);

    return 0;
}

#if 0

before: x is 13
after: x is 1

true is 1, false is 0

#endif
