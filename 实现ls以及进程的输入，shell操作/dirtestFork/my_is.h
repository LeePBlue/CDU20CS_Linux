//
// 自己实现ls
//

#include <unistd.h>
#include "common.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#define MAX 128

typedef struct __tag_file_info
{
    __ino_t         d_ino;                      // inode number 索引节点号
    char            authority[11];              // 文件权限字符串
    __nlink_t       st_nlink;                   // 文件的硬连接数
    char            user_name[NAME_MAX + 1];    // 用户字符串
    char            group_name[NAME_MAX + 1];   // 用户组字符串Q5
    __off_t         st_size;                    // 以字节为单位的文件容量
    struct timespec st_mtim;                    // 文件最后一次修改时间
    char            d_name[NAME_MAX + 1];       // 文件名
    char            real_name[NAME_MAX + 1];    // link文件所指向文件名
} FileInfo;

FileInfo    fileInfoList[MAX];
static char *ls_path = "."; // ls执行路径
static bool ARG_A    = false;
static bool ARG_I    = false;
static bool ARG_L    = false;
static bool ARG_R    = false;
static bool ARG_T    = false;

// 真实执行结果
void real();

// 初始化命令行参数
void init_opt(int argc, char *argv[]);

void read_file_info(char file_name[], FileInfo *pInfo);


int read_path();


static int cmp(const void *a, const void *b);


void output(const int count);

// int main(int argc, char *argv[])
// {
//     // 初始化命令行参数
//     init_opt(argc, argv);

// //    // 真实执行结果
// //    real();

//     output(read_path());

//     return 0;
// }
