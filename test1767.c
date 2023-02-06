#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int un_g_val;
int g_val = 100;

int main(int argc, char* argv[], char* env[])
{
    printf("code addr            : %p\n", main);
    printf("init global addr     : %p\n", &g_val);
    printf("uninit global addr   : %p\n", &un_g_val);

    char* m1 = (char*)malloc(100);

    printf("heap addr            : %p\n", m1);
    printf("stack addr           : %p\n", &m1);

    int i = 0;
    for (i = 0; i < argc; i++) {
        printf("argv addr        : %p\n", argv[i]);   
    }

    for (i = 0; env[i]; i++) {
        printf("env addr         : %p\n", env[i]);
    }
}

