#include"my_is.h"
#include"show_files.h"
#include"common.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[])
{
        pid_t  pid;

        pid = fork();

        if(pid < 0)
        {
                printf("\n\n");
                printf("fork() create child process failure: %s\n",strerror(errno));
                return -1;
        }
        else if(pid == 0)
        {
	   sleep(2);
            printf("all information process PID[ %d ] \n",getpid());
            // 初始化命令行参数
            init_opt(argc, argv);

        //    // 真实执行结果
        //    real();

            output(read_path());
            return 0;
        }
        else    //if(pid > 0;
	{
            sleep(1);
            printf("\n");
            printf("dir  process PID[%d] \n",getpid());
            if (argc < 2)
            {
            my_err("listfile <target ls_path>", __LINE__);
            }
            if (my_readir(argv[1]) < 0)
            {
                my_err("readir failed", __LINE__);
            }
                         printf("\n");
                return 0;
        }
}
