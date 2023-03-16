#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    umask(0);
    // fopen("log.txt", "w");  底层的 open, O_APPEND | O_CREAT | O_TRUNC ，还要带上权限
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("fd: %d\n", fd);

    int cnt = 0;
    const char* str = "V me 50";
    while (cnt < 5) {
        write(fd, str,strlen(str));
        cnt++;
    }

    close(fd);   
    
    return 0;
}

