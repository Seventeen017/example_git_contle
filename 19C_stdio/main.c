/*<stdio.h>头文件定义了用于输入和输出的函数、类型和宏。
 * 最重要的类型是用于声明文件指针的FILE。另外两个常用的类型是 size_t
 * 和fpos_t，size_t是由运算符sizeof产生的无符号整类型；fpos_t类型
 * 定义能够唯一说明文件中的每个位置的对象。由头部 定义的最有用的宏是
 * EOF，其值代表文件的结尾。
 */


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stddef.h>
//如果在window 平台下 需要无阻赛获取标准输入 需要加入 conio.h
//在window下需要用getch 这个连ctrl 都无法打断
//而在linux 可以在控制台输入命令 stty XXX
/* 设置一个输出缓存*/
char outbuf[BUFSIZ];   //#define BUFSIZ 512

//char outbuf[10];
int main(void)
{
#if 0
    char c;
    c = getch();
    while (c != '0') {
        c = getch();
        printf("%d\n",c);
    }
#endif

    //缓存设置
    //setbuf(stdout, outbuf);     //缓存满了就输出 或者 通过fflush

    //    puts("This is a test of buffered output.\n\n");
    //    puts("This output will go into outbuf\n");
    //    puts("and won't appear until the buffer\n");
    //    puts("fills up or we flush the stream.\n");

    /* 可以尝试注释一下fflush看2者不一样 */
    //    fflush(stdout);
    //    memset(outbuf,'0',sizeof(outbuf));
    printf("============================\n");
    printf("%s",outbuf);

    //打开关闭读写文件
    FILE *f_p;
    int ret;
    f_p = fopen("./test.txt","a+");
    ret = fread(outbuf,sizeof(char),BUFSIZ,f_p);
    printf("%d\n",ret);
    printf("%s",outbuf);

    char ar[10] = "seventeen";
    fwrite(&ar,sizeof(char),10,f_p);


    int i = 10; char j = 'g';float k = 0.123;
   // vfprintf(f_p,"%d %c %f",i,j,k); 这个不懂
    return 0;
}

/*
 * 变量：
    typedef size_t
    typedef FILE
    typedef fpos_t

    常量 ：
    NULL 空值
    _IOFBF 表示完全缓冲
    _IOLBF 表示线缓冲
    _IONBF 表示无缓存
    BUFSIZ setbuf函数所使用的缓冲区的大小
    EOF EOF是负整数表示END OF FILE
    FOPEN_MAX (20)同时打开的文件的最大数量
    FILENAME_MAX 文件名的最大长度
    L_tmpnam整数，最大长度的临时文件名
    SEEK_CUR取得目前文件位置
    SEEK_END将读写位置移到文件尾时
    SEEK_SET将读写位置移到文件开头
    TMP_MAXtmpnam最多次数
    stderr标准错误流，默认为屏幕, 可输出到文件。
    stdin标准输入流，默认为键盘
    stdout标准输出流，默认为屏幕

    所有函数：

    clearerr(); 复位错误标志
    fclose(); 关闭一个流。
    feof(); 检测文件结束符
    ferror(); 检查流是否有错误
    fflush();更新缓冲区
    fgetpos(); 移动文件流的读写位置
    fopen();打开文件
    fread(); 从文件流读取数据
    freopen(); 打开文件
    fseek(); 移动文件流的读写位置
    fsetpos();定位流上的文件指针
    ftell(); 取得文件流的读取位置
    fwrite(); 将数据写至文件流
    remove(); 删除文件
    rename(); 更改文件名称或位置
    rewind(); 重设读取目录的位置为开头位置
    setbuf(); 把缓冲区与流相联
    setvbuf(); 把缓冲区与流相关
    tmpfile(); 以wb+形式创建一个临时二进制文件
    tmpnam(); 　产生一个唯一的文件名
    fprintf(); 格式化输出数据至文件
    fscanf(); 格式化字符串输入
    printf(); 格式化输出数据
    scanf(); 格式输入函数
    sprintf(); 格式化字符串复制
    sscanf(); 格式化字符串输入
    vfprintf(); 格式化输出数据至文件
    vprintf(); 格式化输出数据
    vsprintf(); 格式化字符串复制
    fgetc(); 由文件中读取一个字符
    fgets(); 文件中读取一字符串
    fputc(); 将一指定字符写入文件流中
    fputs(); 将一指定的字符串写入文件内
    getc(); 由文件中读取一个字符
    getchar(); 由标准输入设备内读进一字符
    gets(); 由标准输入设备内读进一字符串
    putc(); 将一指定字符写入文件中
    putchar(); 将指定的字符写到标准输出设备
    puts(); 送一字符串到流stdout中
    ungetc(); 　将指定字符写回文件流中
    perror(); 打印出错误原因信息字符串
*/
