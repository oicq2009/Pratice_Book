#include <stdio.h>
#include <unistd.h>

int main(void) {
    FILE* fp = fopen("log.txt", "w");  // 若不存在就创建之
    while (1) {
        printf("I am m a process!\n");
        sleep(1);
    }
}


