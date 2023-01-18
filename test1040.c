#include <stdio.h>

/*
文件指针

缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名
字，文件状态及文件当前的位置等）。这些信息是保存在一个结构体变量中的。该结构体类型是有系统
声明的，取名FILE.
例如，VS2013编译环境提供的 stdio.h 头文件中有以下的文件类型申明

*/

int main(void) {
    // 打开文件
    FILE* pf = fopen("test1041.txt", "r");
    if (pf == NULL) {
        perror("fopen");
        return( 1);
    } else {
        printf("success\n");
    }
    // 写文件
    
    // 关闭文件
    fclose(pf);
    pf = NULL;

    return( 0);
}


