#include <stdio.h>

int main()
{
    int a[3][4] = {0}; // 二维数组

    /* 1 */  printf("%d\n",sizeof(a)); // 48
    /* 2 */  printf("%d\n",sizeof(a[0][0])); // 4
    /* 3 */  printf("%d\n",sizeof(a[0])); // 16
    /* 4 */  printf("%d\n",sizeof(a[0]+1)); // 4/8
    /* 5 */  printf("%d\n",sizeof(*(a[0]+1)));// 4
    /* 6 */  printf("%d\n",sizeof(a+1)); // 4
    /* 7 */  printf("%d\n",sizeof(*(a+1))); // 16
    /* 8 */  printf("%d\n",sizeof(&a[0]+1)); // 4/8
    /* 9 */  printf("%d\n",sizeof(*(&a[0]+1))); // 16
    /* 10 */ printf("%d\n",sizeof(*a)); // 16
    /* 11 */ printf("%d\n",sizeof(a[3])); // 16

    return 0;
}
