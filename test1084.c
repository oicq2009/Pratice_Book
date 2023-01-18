#include <stdio.h>

struct S
{
    char c;
    int i;
} s1, s2;

struct B123
{
    double d;
    struct S s;
    char c;
};

int main()1
{
    struct B sb = {3.14, {'w', 100}, 'q'};
    printf("%lf %c %d %c\n", sb.d, sb.s.c, sb.s.i, sb.c);
    
    return 0;
}




