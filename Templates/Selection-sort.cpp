//ѡ������
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N], n;

void selection_sort()//ѡ������, Ĭ�ϴ�С����
{
	for(int i = 1; i < n; i++)//��С����Ѱ������Ϊi����
	{
    	int ith = i;//��ith��¼����Ϊi�������±�
    	for(int j = i + 1; j <= n; j++)//��i + 1��ʼѰ��, ��Ϊǰ��Ķ����ź����
		{
    		if(a[j] < a[ith]) ith = j;//��������j������С�͸���
      	}
    	swap(a[i], a[ith]);//���������i����������Ϊi����
  	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	selection_sort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

