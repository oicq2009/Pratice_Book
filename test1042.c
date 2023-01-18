#include<stdio.h>

// 文件的顺序读写

int main(void) {
    FILE* pf = fopen("test1043.dat", "w");
    if(pf == NULL) {
        perror("fopen");
        return( 1);
    }
    // 写文件
    fputc('a', pf);
    fputc('b', pf);
    fputc('c', pf);

    // 关闭文件
    fclose(pf);
    pf = NULL;

    return( 0);
}



