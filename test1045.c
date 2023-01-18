#include <stdio.h>

// fgetc 从标准输入流读取信息

int main(void) {
    int ret = fgetc(stdin);
    printf("%c\n", ret);

    ret = fgetc(stdin);
    printf("%c\n", ret);

    ret = fgetc(stdin);
    printf("%c\n", ret);

    return( 0);
}

