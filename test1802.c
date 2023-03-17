#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define NUM   1024
#define TRUE  1 
#define FALSE 0
#define SEP   " "

char command_line[NUM];                                      // 接收命令行内容
char* command_args[SIZE];                                    // 存储切分后的字符串

int main (
    void
    )
{
    while (TRUE) {
        /* Step1: 显示提示符 */
        printf("[foxny@cspro ~] # ");                        // 主机名与当前目录
        fflush(stdout);                                      // 清刷缓冲区
      
        /* Step2: 获取用户输入 */      
        memset (                                             // 初始化内存
            command_line,       
            '\0',       
            sizeof(command_line) * sizeof(char)      
        );      
        fgets(command_line, NUM, stdin);                     // 从键盘获取，标准输入stdin 
        command_line[strlen(command_line) - 1] = '\0';      
              
        /* TEST */ // printf("%s\n", command_line);          // 打印结果
      
      
        /* Step3: 字符串切分 */      
        command_args[0] = strtok(command_line, SEP);         // 按空格切分
        int idx = 1;
        
        // 添加颜色
        if (strcmp(command_args[0] == 0, "ls") == 0) {
            command_args[idx++] = (char*)"--color=auto";
        }

        while (command_args[idx++] = strtok(NULL, SEP)) {
            ;
        }

        /* TEST */ for (int i = 0; i < idx; i++) {
        //     printf("%d : %s\n", command_args[i]);
        // }
        // printf("%s\n", command_line);

        /* Step4: 创建进程，执行 */
        pid_t id = fork();
        if (id == 0) {
            /* child */
            /* 程序替换*/
            execvp(command_args[0], command_args);
            exit(-1);
        }
        /* Father */
        int status;
        pid_t ret = waitpid(id, &status, 0);
        if (ret > 0) {
            printf("等待成功！sig: %d, code: %d\n", status&0x7F, (status>>8)&0xFF);
        }
    }
}






