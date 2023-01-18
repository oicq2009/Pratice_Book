#include <stdio.h>

// fscnaf
struct S {
    char arr[10];
    int num;
    float sc;
};

int main(void) {
    struct S s = {"abcdef", 10, 5.5f};
    // 对格式化的数据进行写文件
    FILE* pf = fopen("test1049.dat", "r");
    if(NULL == pf) {
        perror("fopen");
        return( 1);
    }
    // 读文件
    fscanf(pf, "%s %d %f", s.arr, &(s.num), &(s.sc));
    // 打印
    printf("%s %d %f\n", s.arr, s.num, s.sc);
    // fprintf(stdout, "%s %d %f\n", s.arr, s.num, s.sc); // 一样的
    
    // 关闭文件
    fclose(pf);
    pf = NULL;
    
    return( 0);
}
