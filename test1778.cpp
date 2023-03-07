#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>

typedef void (* handler_t)();

// 方法集
std::vector<handler_t> handlers;

void func1() {
    printf("Hello，我是方法1\n");
}
void func2() {
    printf("Hello，我是方法2\n");
}

void Load() {
    // 加载方法
    handlers.push_back(func1);
    handlers.push_back(func2);
}

int main(void)
{
    pid_t id = fork();
    if (id == 0) {
        // 子进程
        while (1) {
            printf("子进程：我的PID: %d，我的PPID: %d\n", getpid(), getppid());
            sleep(3);
        }
        exit(233);
    }
    else if (id > 0) {
        // 父进程

        /* 基于非阻塞的轮训等待方案 */
        int status = 0;
        while (1) {
            pid_t ret = waitpid(-1, &status, WNOHANG);
            if (ret > 0) {          // 等待成功
                printf("等待成功，%d，退出信号: %d，退出码: %d\n", ret, status&0x7F, (status>>8)&0xFF);
            }
            else if (ret == 0) {    // 等待成功，但是子进程没有退出
                printf("父进程：子进程好了没？哦，还没，那我先做其他事情啦\n");
                if (handlers.empty()) {
                    Load();
                }
                for (auto f : handlers) {
                    f();  // 回调处理对应的任务
                }

                sleep(1);
            }
            else {
                // 出错了，暂时不作处理
            }
        }
    }
    else {
        // 什么也不做
    }
}



//如果你想要你的程序直接父进程做更多的事情，把方法加到 Load 里就可以了
