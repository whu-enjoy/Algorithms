/*******************************************************************************
����Ա   : enjoy5512
ʱ  ��   : 2016��4��16�� 20:22:05
����˵�� : Ѱ�������еĶ���Ԫ��,������,�������Ӧ����
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10        //�����С

/*
����˵��:
    �ݹ��������,Ѱ�Ҷ���Ԫ��
�������:
    int A[]  : ��������
    int n    : �����С
    int m    : �ӵڼ���Ԫ�ؿ�ʼ����
�������:
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
		return c;     //�ݹ����ʱ,c��С��Χ�ڳ��ֵĴ���������%50
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

	c = Candidate(A, n - 1, 0);  //�õ������Ƕ���Ԫ�ص�����Ԫ��

	count = 0;

	for (j = 0;j < n;j++)
	{
		if (c == A[j])
		{
			count++;
		}
	}

	if (count > n/2)   //���c���ֵĴ����Ƿ����n/2,�����Ƕ���Ԫ��,������
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
