/*************************************************************************
    > Copyright (C), 2017-2018, enjoy5512
    > File Name       : getRandData.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2017年03月13日 星期一 18时29分04秒
    > Version         : 1.0
    > Description     : 
    > Function List   : 
    > History         : 
      <author>    <time>  <version>   <desc>
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandData(void);

/************************************************************************
    > Function       : 
    > Description    : 
    > Input          : 
    >    
    > Return         : 
************************************************************************/
int main(int argc,char *argv[])
{
    getRandData();
    
    return 0;
}

/************************************************************************
    > Function       : void getRandData(void) 
    > Description    : 这个函数会接收用户一个输入数据dataSize,然后产生
                       0-dataSize之间的数的随机排列
    > Input          : 无
    >    
    > Return         : 无
************************************************************************/
void getRandData(void)
{
    int i = 0; /*循环变量*/
    int randPos = 0; /*随机位置*/
    int dataSize = 0;  /*数据大小*/

    int* arr = 0;      /*用于保存随机数组*/

    FILE* dataFilePoint = NULL; /*数据保存文件指针*/

    dataFilePoint = fopen("randData.txt", "wr+");
    if (NULL == dataFilePoint)
    {
        perror("fopen ./randData.txt");
        exit(1);
    }

    /*循环获取用户输入*/
    while (1)
    {
        fprintf(stdout, "请输入需要产生的数据量(1-1000000):");
        fscanf(stdin, "%d", &dataSize);

        /*检查输入数据的合法性*/
        if (0 < dataSize && dataSize < 1000001)
        {
            break;
        }
        else
        {
            fprintf(stderr, "请输入正确的数字,1-1000000!\n\n");
        }
    }

    /*分配dataSize个int大小的数组*/
    arr = (int*)malloc(sizeof(int)*dataSize);
    if (NULL == arr)
    {
        perror("malloc arr");
        fclose(dataFilePoint);
        exit(2);
    }

    /*为arr数组赋初值*/
    for (i = 0; i < dataSize; i++)
    {
        arr[i] = i;
    }

    /*设置随机种子*/
    srand(time(NULL));
    i = dataSize;
    while (i)
    {
        /*获取随机位置*/
        randPos = rand()%dataSize;
        /*如果这个数没有出现过,则将这个数输出到文件,否则继续循环*/
        if (-1 != arr[randPos])
        {
            fprintf(dataFilePoint,"%7d", randPos);
#ifdef DEBUG
            fprintf(stdout, "%7d", randPos);
#endif
            arr[randPos] = -1;
            i--;
        }
    }
    fprintf(stdout, "\nget rand data success!\n");

    /*释放分配的内存*/
    free(arr);
    /*关闭文件指针*/
    fclose(dataFilePoint);
}
