//Ͱ����
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, w, a[N];//wΪֵ��
vector<int> bucket[N];

void insertion_sort(vector<int> &A)//�����õĲ�������
{
	for(int i = 1; i < A.size(); i++)
	{
		int key = A[i], j = i - 1;
		while(j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = key;
	}
	return ;
}

void bucket_sort()//Ͱ����
{
	int bucket_size = w / n + 1;
	for(int i = 0; i < n; i++)
	{
		bucket[i].clear();
	}
	for(int i = 1; i <= n; i++)
	{
		bucket[a[i] / bucket_size].emplace_back(a[i]);
		//�ֿ�
		//emplace_back��push_backЧ����ͬ,���ٶȸ���
	}
	int p = 0;
	for(int i = 0; i < n; i++)
	{
		insertion_sort(bucket[i]);
		for(int j = 0; j < bucket[i].size(); j++)
		{
			a[++p] = bucket[i][j];//���ºϲ�
		}
	}
	return ;
}

int main()
{
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	bucket_sort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

