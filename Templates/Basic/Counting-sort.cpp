//��������
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, W = 1e5 + 5;//WΪ���������ݵ�ֵ���С

int a[N], n, w, cnt[W], b[N];

void counting_sort()//Ĭ�ϴ�С��������
{
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;//����ÿ�������ִ���
	}
	for(int i = 1; i <= w; i++)
	{
		cnt[i] += cnt[i - 1];//��ÿ�������ִ�����ǰ׺��
	}
	for(int i = n; i >= 1; i--)
	{
		b[cnt[a[i]]--] = a[i];//�����������ÿ����������,����b��
	}
}

int main()
{
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	counting_sort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}

