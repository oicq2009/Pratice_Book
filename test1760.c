#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t id = fork();

    /* id:  0 子进程， >0 父进程 */
    if (id == 0) {
        // child
        while (1) {
            printf("我是子进程，我的pid: %d，我的父进程是 %d\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        // parent
        while (1) {
            printf("我是父进程，我的pid: %d，我的父进程是 %d\n", getpid(), getppid());
            sleep(1);
        }
    }
}



