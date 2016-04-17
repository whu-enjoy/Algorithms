/*******************************************************************************
����Ա   : enjoy5512
ʱ  ��   : 2016��4��16�� 20:22:05
����˵�� : Ͱ����
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50        //�����С
#define K 5

/*
����˵��:
    �������������в�������
�������:
    int A[]  : ��������
�������:
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
����˵��:
    Ͱ����
�������:
    int A[]  : ��������
    int n    : �����С
�������:
    0
    */
int Bucket(int A[],int n)
{
	int order[K] = {0};            //Ͱ��ǰ���һ��Ԫ�ص����
	int bucket[K][SIZE+1] = {0};    //K��Ͱ,ÿ��Ͱ��һ��Ԫ����Ͱ��ǰ���һ��Ԫ�ص����

	int i = 0;
	int j = 0;
	int k = 0;
	int max = A[0];

	for (i = 1; i < n; i++)        //���ҳ������������Ԫ��
	{
		if (max < A[i])
		{
			max = A[i];
		}
	}

	for (i = 0; i < n; i++)        //��������,��Ԫ�طŵ���ӦͰ��
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
		InsertionSort(bucket[i]);   //��ÿ��Ͱ���в�������,���������Ľ���ŵ��ϲ���ԭ��
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

	printf("����ԭ����˳�� : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	bucket(A,n);      //����	
	printf("\n������˳��   : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
