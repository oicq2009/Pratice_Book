#include <stdio.h>
#include <unistd.h>
#include <string.h>

// 命令行版本的计算器
int main(int argc, char const *argv[])
{
    // char* argv[]  是什么类型？里面放什么呢？
    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argc[i]);
    // }

    if (argc != 4) {
        printf("Usage: %s [-a|-s|-m|-d] x y\n", argv[0]);
        return 0;
    }
    
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);

    if (strcmp("-a", argv[1]) == 0)
        printf("%d + %d = %d\n", x, y, x + y);

    else if (strcmp("-s", argv[1]) == 0)
        printf("%d - %d = %d\n", x, y, x - y);

    else if (strcmp("-m", argv[1]) == 0)
        printf("%d * %d = %d\n", x, y, x * y);

    else if (strcmp("-d", argv[1]) == 0 && y != 0)
        printf("%d / %d = %d\n", x, y, x / y);
    
    else
        printf("Usage: %s [-a|-s|-m|-d] x y\n", argv[0]);
    
    return 0;
}

