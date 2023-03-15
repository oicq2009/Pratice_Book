#include <stdio.h>

#define PRINT_A   0x1     // 0000 0001
#define PRINT_B   0x2     // 0000 0010
#define PRINT_C   0x4     // 0000 0100
#define PRINT_D   0x8     // 0000 1000
#define PRINT_DFL 0x0

// open
void Show (
    int flags  /* 传递标志位 */
    )
{
    if (flags & PRINT_A)     printf("Hello A\n");
    if (flags & PRINT_B)     printf("Hello B\n");
    if (flags & PRINT_C)     printf("Hello C\n");
    if (flags & PRINT_D)     printf("Hello D\n");
    if (flags == PRINT_DFL)  printf("Hello Default\n");
}

int main(void)
{
    /* 我想打谁，只需要传对应的标记位即可 */
    printf("# PRINT_DFL: \n");
    Show(PRINT_DFL);

    printf("# PRINT_A: \n");
    Show(PRINT_A);

    printf("# PRINT_B: \n");
    Show(PRINT_B);

    printf("# PRINT_A AND PRINT_B: \n");
    Show(PRINT_A | PRINT_B);

    printf("# PRINT_C AND PRINT_D: \n");
    Show(PRINT_C | PRINT_D);

    printf("# PRINT_A AND PRINT_B AND PRINT_C AND PRINT_D: \n");
    Show(PRINT_A | PRINT_B | PRINT_C | PRINT_D);

    return 0;
}

