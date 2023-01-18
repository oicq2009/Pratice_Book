#include <stdio.h>

struct S
{
    char c1; // 1
    int i; // 4
    char c2; // 1
};

int main()
{
    struct S s = {0};
    printf("%d\n", sizeof(s));

    return 0;
}

