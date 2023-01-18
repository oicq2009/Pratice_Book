#include <stdio.h>
#include <stddef.h>

struct S
{
    char c1; //1
    int i; // 4
    char c2; // 1
};

int main()
{
    printf("%d\n", offsetof(struct S, c1));
    printf("%d\n", offsetof(struct S, i));
    printf("%d\n", offsetof(struct S, c2));

    return 0;    
}


