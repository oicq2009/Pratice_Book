#include<stdio.h>

// 读文件
// 使用fgetc从文件里读数据

// fgetc读取错误或者读取结束都会返回额EOF
int main(void) {
    FILE* pf = fopen("test1043.dat", "r");
    if(pf == NULL) {
        perror("fopen");
        return( 1);
    }
    // 读文件
    int ret = fgetc(pf);
    printf("%c\n", ret);

    ret = fgetc(pf);
    printf("%c\n", ret);

    ret = fgetc(pf);
    printf("%c\n", ret);

    // 关闭文件
    fclose(pf);
    pf = NULL;

    return( 0);
}
