/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016��5��6�� 16:17:29
#
# Filename      : GetTreeHigh.c
#
# Description   : ����������ڼ���������ĸ߶�
#
=============================================================================*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
����˵�� :
	�������������ʾ��,�������²����ݲ��ó���32��,ÿ�����ݲ��ó�����λ��
	�����ʽ����������
������� :
	tree : ��Ҫ��ʾ����
	n    : ���Ĵ�С
������� :
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

	high = log(n)/log(2) + 1;         //����ѵĸ߶�

	for(k = 0; k < high - 1;k++)
	{
		count = pow(2,k);             //ÿ�д�ӡ��������
		backspace = pow(2,high-k)-1;  //ÿ����������֮��Ŀո���

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
	for(; i < n; i++)     //��ӡ���һ������
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
����˵�� :
	����������ڼ������ĸ߶�
������� :
	tree : ��Ҫ�������
	node : ��ǰ�ڵ�����
	n    : �ѵĴ�С
������� :
	0
*/
int calc(int tree[], int node, int high)
{
	int a = 0;
	int b = 0;

	if ( 0 == tree[node])                    //������ڵ�Ϊ��,�򷵻ص�ǰ�����߶�
	{
		return high;
	}
	else
	{
		high++;                              //���ڵ㲻Ϊ��,���������ӽڵ�
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
	printf("���ĸ߶��� : %d\n",high);

	system("pause");
	return 0;
}