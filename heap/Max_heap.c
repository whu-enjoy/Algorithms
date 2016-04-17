/******************************************************************************
	程序员       : enjoy5512
	最后修改时间 : 2016年3月30日 17:09:08
	函数说明     : 这个代码用来测试最大堆的插入删除排序等用法
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Size 11

/*
函数说明 :
	这个函数用于最大堆的上移操作
输入参数 :
	heap : 需要移动的堆
	i    : 需要移动的数在堆中的位置(1-n)
输出参数 :
	0
*/
int SiftUp(int heap[],int i)
{
	int temp = 0;

	//循环移动,i等于1则退出
	for (;1 != i;i = i / 2)
	{
		//子节点大于父节点则上移,否则退出
		if (heap[i - 1] > heap[(i - 2) / 2 ])
		{
			temp = heap[i - 1];
			heap[i - 1] = heap[(i -2) / 2];
			heap[(i -2) / 2] = temp;
		}
		else
		{
			break;
		}
	}

	return 0;
}

/*
函数说明 :
	这个函数用于最大堆的下移操作
输入参数 :
	heap : 需要移动的堆
	i    : 需要移动的数在堆中的位置(1-n)
	n    : 堆的大小
输出参数 :
	0
*/
int SiftDown(int heap[],int i,int n)
{
	int temp = 0;

	//循环移动,直到子节点大于堆的大小时退出
	for (;2*i <= n;)
	{
		i = i * 2;

		//寻找子节点中最大的子节点,作为下移的对象
		if ((i + 1 <= n) && (heap[i] > heap[i - 1]))
		{
			i = i + 1;
		}

		//若父节点比子节点小则下移,否则结束
		if (heap[(i - 2) / 2] < heap[i - 1])
		{
			temp = heap[(i - 2) / 2];
			heap[(i - 2) / 2] = heap[i - 1];
			heap[i - 1] = temp;
		}
		else
		{
			break;
		}

	}

	return 0;
}

/*
函数说明 :
	这个函数用于最大堆的插入操作
输入参数 :
	oldheap : 原来的堆
	n       : 原来的堆的大小
	newheap : 新的堆
	x       : 需要插入的数据
输出参数 :
	0
*/
int Insert(int oldheap[],int n,int newheap[],int x)
{
	int i = 0;

	//循环将原来的堆复制到新的堆
	for(i = 0 ;i < n ;i++)
	{
		newheap[i] = oldheap[i];
	}
	newheap[n] = x;             //将插入的值插入到新的堆的最后一个
	SiftUp(newheap,n+1);        //上移操作

	return 0;
}

/*
函数说明 :
	这个函数用于最大堆的删除操作
输入参数 :
	oldheap : 原来的堆
	n       : 原来的堆的大小
	newheap : 新的堆
	i       : 需要删除的数据在堆中的位置
输出参数 :
	0
*/
int Delete(int oldheap[],int n,int newheap[],int i)
{
	int j = 0;
	int temp = 0;

	//循环将原来的堆的前n-1个数据复制到新的堆
	for (j = 0; j < n - 1; j++)
	{
		newheap[j] = oldheap[j];
	}
	temp = newheap[i - 1];            //保存堆要删的元素
	newheap[i - 1] = oldheap[n - 1];  //将要删除的数据与最后一个元素交换位置

	//如果删除的数据比最后一个数据小,则上移,否则下移
	if (newheap[i - 1] > temp)        
	{
		SiftUp(newheap,i);
	}
	else
	{
		SiftDown(newheap,i,10);
	}
	oldheap[n - 1] = 0;                //将原来的堆最后一个元素置为0

	return 0;
}

/*
函数说明 :
	这个函数用于最大堆的删除最大值操作
输入参数 :
	heap : 需要删除元素的堆
	n    : 堆的大小
输出参数 :
	x    : 堆的最大值
*/
int DeleteMax(int heap[],int n)
{
	int x = 0;

	x = heap[0];
	Delete(heap,n,heap,1);             //删除第一个元素

	return x;
}

/*
函数说明 :
	这个函数用于最大堆的创建操作
输入参数 :
	heap : 需要创建的堆
	n    : 堆的大小
输出参数 :
	0
*/
int MakeHeap(int heap[],int n)
{
	int i = 0;

	//遍历所有节点的父节点,对每个遍历的节点进行下移操作
	for(i = n/2;i > 0;i--)
	{
		SiftDown(heap,i,n);
	}

	return 0;
}

/*
函数说明 :
	这个函数用于最大堆的排序操作
输入参数 :
	heap : 需要排序的堆
	n    : 堆的大小
输出参数 :
	0
*/
int HeapSort(int heap[],int n)
{
	int i = 0;
	int temp = 0;

	MakeHeap(heap,n);             //先创建堆

	//每次取出最大的元素放到数组的最后面
	//然后每次对堆的第一个元素进行下移操作(范围1-(i-1))
	for(i = n; i > 1; i--)
	{
		temp = heap[0];
		heap[0] = heap[i-1];
		heap[i-1] = temp;
		SiftDown(heap,1,i-1);
	}
}


/*
函数说明 :
	这个函数用于显示堆,堆的最下层数据不得超过40,每个数据不得超过两位数
	否则格式将出现问题
输入参数 :
	heap : 需要显示的堆
	n    : 堆的大小
输出参数 :
	0
*/
int ShowHeap(int heap[],int n)
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
			printf("%2d",heap[count+i-1]);
			for(j = 0;j < backspace;j++)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	i = pow(2,k) - 1;
	printf("%d",heap[i]);
	i++;
	for(; i < n; i++)     //打印最后一排数据
	{
		if(0 != heap[i])
		{
			printf("  %2d",heap[i]);
		}
	}
	printf("\n");

	return 0;
}

int main(void)
{
	int heap[Size] = {4,3,12,10,11,13,7,30,17,26,0};

	printf("数组原来的样子:\n");
	ShowHeap(heap,Size - 1);

	printf("\n\n创建堆:\n");
	MakeHeap(heap,Size - 1);
	ShowHeap(heap,Size - 1);

	printf("\n\n第九个位置上的数变成20:\n");
	heap[8] = 20;
	SiftUp(heap,9);
	ShowHeap(heap,Size - 1);

	printf("\n\n第二个位置上的数变成2:\n");
	heap[1] = 2;
	SiftDown(heap,2,Size-1);
	ShowHeap(heap,Size - 1);

	printf("\n\n插入一个元素15:\n");
	Insert(heap,Size - 1,heap,15);
	ShowHeap(heap,Size);

	printf("\n\n删除第三个元素13:\n");
	Delete(heap,Size,heap,3);
	ShowHeap(heap,Size);

	printf("\n\n删除最大值:\n");
	DeleteMax(heap,Size-1);
	ShowHeap(heap,Size-1);

	printf("\n\n堆排序:\n");
	HeapSort(heap,Size-2);
	ShowHeap(heap,Size-2);

	system("pause");
	return 0;
}
