#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    // 给它们都带上 \n
    printf("Hello printf\n");    // stdout -> 1
    fprintf(stdout, "Hello fprintf!\n");
    fputs("Hello fprintf!\n", stdout);

    const char* msg = "Hello write\n";
    write(1, msg, strlen(msg));

    sleep(5);

    return 0;
}


