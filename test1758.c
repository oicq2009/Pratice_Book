#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    while (1) {
        printf("I am m a process! , pid: %d, ppid: %d\n",getpid(), getppid());
        sleep(1);
    }
}


