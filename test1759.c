#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t id = fork();

    printf("Hello, World! id: %d\n", id);
    sleep(1);
}




