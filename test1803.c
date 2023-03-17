#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>  // 需引入头文件

int main(void)
{
    umask(0);
    int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
    if (fd < 0) {
        perror("open"); 
        return 1;
    }
    printf("fd: %d\n", fd); 

    close(fd);

    return 0;
}


