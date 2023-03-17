#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    umask(0);
    int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
    if (fd < 0) {
        perror("open"); 
        return 1;
    }
    printf("fd: %d\n", fd); 
    
    // 向文件写入 2 行信息
    int cnt = 0;
    const char* str = "666\n";
    while (cnt < 2) {
       write(fd, str, strlen(str));
       cnt++;
    }

    close(fd);

    return 0;
}

