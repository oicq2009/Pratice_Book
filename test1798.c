#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>

int main()
{
    umask(0);
    int fd = open("log.txt", O_APPEND | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("fd: %d\n", fd);

    return 0;
}



