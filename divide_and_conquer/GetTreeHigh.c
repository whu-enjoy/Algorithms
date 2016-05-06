/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016年5月6日 16:17:29
#
# Filename      : GetTreeHigh.c
#
# Description   : 这个代码用于计算二叉树的高度
#
=============================================================================*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
函数说明 :
	这个函数用于显示树,树的最下层数据不得超过32个,每个数据不得超过两位数
	否则格式将出现问题
输入参数 :
	tree : 需要显示的树
	n    : 树的大小
输出参数 :
	0
*/
int ShowTree(int tree[],int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	int backspace = 0;
	int high = 0;

	high = log(n)/log(2) + 1;         //求出堆的高度

	for(k = 0; k < high - 1;k++)
	{
		count = pow(2,k);             //每行打印的数据数
		backspace = pow(2,high-k)-1;  //每行两个数据之间的空格数

		for(j = 0;j < (backspace-1)/2;j++)
		{
			printf("  ");
		}
		for(i = 0; i < count; i++)
		{
			printf("%2d",tree[count+i-1]);
			for(j = 0;j < backspace;j++)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	i = pow(2,k) - 1;
	printf("%d",tree[i]);
	i++;
	for(; i < n; i++)     //打印最后一排数据
	{
		if(4294967295 != tree[i])
		{
			printf("  %2d",tree[i]);
		}
	}
	printf("\n");

	return 0;
}

/*
函数说明 :
	这个函数用于计算树的高度
输入参数 :
	tree : 需要计算的树
	node : 当前节点的序号
	n    : 堆的大小
输出参数 :
	0
*/
int calc(int tree[], int node, int high)
{
	int a = 0;
	int b = 0;

	if ( 0 == tree[node])                    //如果本节点为空,则返回当前子树高度
	{
		return high;
	}
	else
	{
		high++;                              //本节点不为空,继续计算子节点
		a = calc(tree, 2*(node+1)-1, high);
		b = calc(tree, 2*(node+1), high);
		return (a>b?a:b);
	}
}

int main(void)
{
	int tree[127] = {1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1};
	int high = 0;

	system("mode 130,40");
	ShowTree(tree,63);

	high = calc(tree,0,high);
	printf("树的高度是 : %d\n",high);

	system("pause");
	return 0;
}