#include <stdio.h>

/* 读什么就打什么   mycat */
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE* pf = fopen(argv[1], "r");    // 读取
    if (pf == NULL) {
        perror("fopen");
        return 1;
    }

    char buffer[64];
    while (fgets(buffer, sizeof(buffer), pf) != NULL) {
        printf("%s", buffer);
    }

    fclose(pf);
}

