#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t id = fork();
    if (id == 0) {
        // child
        int cnt = 5;
        while (cnt) {
            printf("我是子进程，我还剩下 %ds\n", cnt--);
            sleep(1);
        }
        printf("我是子进程，我已经变僵尸了，等待被检测\n");
        exit(0);
    }
    else {
        // father
        while (1) {
            sleep(1);
        }
    }
}




