#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    umask(0);

    int fd = open("log.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("fd: %d\n", fd);

    char buffer[128];
    ssize_t s = read(fd, buffer, sizeof(buffer) - 1);
    if (s > 0) {
        buffer[s] = '\0';  // 最后字符串序列设置为 '\0' 
        printf("%s", buffer);
    }


    close(fd);   
    
    return 0;
}


// open close wait write   底层四大文件接口
