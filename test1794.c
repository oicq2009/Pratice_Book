#include <stdio.h>

int main(void)
{
    FILE* pf = fopen("log.txt", "r"); // 读
    if (pf == NULL) {
        perror("fopen");
        return 1;
    }

    char buffer[64];
    
    while (fgets(buffer, sizeof(buffer), pf) != NULL) {
        // 打印读取到的内容
        printf("echo: %s", buffer);
    }

    fclose(pf);
}



