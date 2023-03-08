#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) 
{
    printf("我是父进程，我的PID是： %d\n", getpid());
    pid_t id = fork();
    if (id == 0) {
        /* child 
           我们想让子进程执行全新的程序 */
        printf("我是子进程，我的PID是：%d\n", getpid());
        execl("/usr/bin/ls", "ls", "-a", "-l", NULL);  /* 让子进程执行替换 */

        exit(1);   /* 只要执行了exit，就意味着 excel 系列函数失败了，终止子进程*/
    }

    /* 一定是父进程 */
    int status = 0;
    int ret = waitpid(id, &status, 0);
    if (ret == id) {
        /* 等待成功 */
        sleep(2);  
        printf("父进程等待成功！\n");
    }

    return( 0);
}



