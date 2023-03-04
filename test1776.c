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
        int cnt = 5;   // 循环5次
        // child
        while (1) {
            // 五秒之内运行状态
            printf("我是子进程，我正在运行... Pid: %d\n", getpid());
            sleep(1);

            // 五秒之后子进程终止
            cnt--;
            if (cnt == 0) {
                break; 
            }
        }

        exit(13);   // 方便辨识，推出码我们设置为13，这是我们的预期结果
    }
    else {
        printf("我是父进程: pid: %d，我将耐心地等待子进程！\n", getpid());

        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if (ret > 0) {   // 等待成功
            if (WIFEEXITED(status)) {
                printf("子进程正常退出，退出码: %d\n", WEXITSTATUS(status));
            }
            // printf("等待成功，ret: %d, 我所等待的子进程退出码: %d\n", ret, (status>>8)&0xFF);
        }
    }
}









