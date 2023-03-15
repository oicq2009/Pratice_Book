#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // /* 主动更改当前进程的 cwd */
    // chdir("/home/foxny/code");

    FILE* pf = fopen("log.txt", "w"); // 写入
    if (pf == NULL) {
        perror("fopen");
        return 1;
    }

    /* 获取进程 pid */
    printf("Mypid: %d\n", getpid());

    /* 打开文件后，等一等，方便查询 */
    while (1) {
        sleep(1);
    }

    const char* msg = "牛魔酬宾!";
    int count = 1;
    while (count <= 10) {
        fprintf(pf, "%s: %d\n", msg, count++);
    }

    fclose(pf);
}


