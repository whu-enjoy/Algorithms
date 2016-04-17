/*******************************************************************************
程序员   : enjoy5512
时  间   : 2016年4月16日 20:22:05
程序说明 : 桶排序
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50        //数组大小
#define K 5

/*
函数说明:
    对输入的数组进行插入排序
输入参数:
    int A[]  : 输入数组
输出参数:
    0
    */
int InsertionSort(int A[])
{
	int i = 0;
	int j = 0;
	int newdata = 0;

	for (i = 2; i < A[0]+1; i++)
	{
		newdata = A[i];
		for (j = i - 1; j >= 0 && A[j] > newdata; j--)
		{
			A[j+1] = A[j];
		}
		A[j+1] = newdata;
	}

	return 0;
}

/*
函数说明:
    桶排序
输入参数:
    int A[]  : 输入数组
    int n    : 数组大小
输出参数:
    0
    */
int Bucket(int A[],int n)
{
	int order[K] = {0};            //桶当前最后一个元素的序号
	int bucket[K][SIZE+1] = {0};    //K个桶,每个桶第一个元素是桶当前最后一个元素的序号

	int i = 0;
	int j = 0;
	int k = 0;
	int max = A[0];

	for (i = 1; i < n; i++)        //先找出输入数组最大元素
	{
		if (max < A[i])
		{
			max = A[i];
		}
	}

	for (i = 0; i < n; i++)        //遍历数组,将元素放到相应桶中
	{
		for (j = 1; j <= K; j++)
		{
			if (A[i] >= max*(j-1)/K + 1 && A[i] <= max*j/K)
			{
				bucket[j-1][order[j-1]+1] = A[i];
				order[j-1]++;
				bucket[j-1][0]++;
				break;
			}
		}
	}

	j = 0;
	for (i = 0; i < K; i++)
	{
		InsertionSort(bucket[i]);   //对每个桶进行插入排序,并将排序后的结果放到合并到原组
		for (k = 1; k < bucket[i][0]+1; k++)
		{
			A[j] = bucket[i][k];
			j++;
		}
	}

	return 0;
}

int main(void)
{
	int A[SIZE] = {0};

	int c = 0;
	int count = 0;
	int i = 0;
	int n = 10;

	printf("please input the size of the array(Max size 50):");
	scanf("%d",&n);
	printf("please input the number : ");
	for (i = 0; i < n && i < SIZE; i++)
	{
		scanf("%d",&A[i]);
	}

	printf("数组原来的顺序 : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	bucket(A,n);      //排序	
	printf("\n排序后的顺序   : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
