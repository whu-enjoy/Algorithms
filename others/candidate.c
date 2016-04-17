/*******************************************************************************
程序员   : enjoy5512
时  间   : 2016年4月16日 20:22:05
程序说明 : 寻找数组中的多数元素,若存在,则输出相应的数
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10        //数组大小

/*
函数说明:
    递归遍历数组,寻找多数元素
输入参数:
    int A[]  : 输入数组
    int n    : 数组大小
    int m    : 从第几个元素开始遍历
输出参数:
    0
    */
int Candidate(int A[],int n, int m)
{
	int j = m;
	int c = A[m];
	int count = 1;

	for (;j < n-1 && count > 0;)
	{
		j++;
		if (c == A[j])
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	if (j == n-1)
	{
		return c;     //递归结束时,c在小范围内出现的次数至少有%50
	}
	else
	{
		return Candidate(A, n, j+1);
	}

}

int main(void)
{
	int A[SIZE] = {0};

	int c = 0;
	int count = 0;
	int j = 0;
	int n = 0;

	printf("please input the size of the array:");
	scanf("%d",&n);
	printf("please input the number : ");
	for (j = 0; j < n ; j++)
	{
		scanf("%d",&A[j]);
	}

	c = Candidate(A, n - 1, 0);  //得到可能是多少元素的数组元素

	count = 0;

	for (j = 0;j < n;j++)
	{
		if (c == A[j])
		{
			count++;
		}
	}

	if (count > n/2)   //检查c出现的次数是否大于n/2,是则是多数元素,否则不是
	{
		printf("the candidate is %d\n",c);
	}
	else
	{
		printf("there is no candidate num!\n");
	}
	

	system("pause");
	return 0;
}
