#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (
    void
    ) 
{
    pid_t id = fork();
    if (id == 0) {
        // 子进程一直不退出，父进程会一直等待。
        // child
        while (1) {
            printf("我是子进程，我正在运行... Pid: %d\n", getpid());
            sleep(1);
        }

        exit(13);
    }
    else {
        printf("我是父进程: pid: %d，我将耐心地等待子进程！\n", getpid());
        
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if (ret > 0) {   // 等待成功
            printf("等待成功，ret: %d, 我所等待的子进程退出码: %d\n, 退出信号是: %d", ret, (status>>8)&0xFF, status&0x7F);
        }

    }
}







