//��������
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N], n;

void insertion_sort()//Ĭ�ϴ�С��������
{
	for(int i = 1; i <= n; i++)//ö��ÿ��δ�����λ��
	{
	    int key = a[i];//��key��¼��ǰλ��ֵ
    	int j = i - 1;
    	while(j >= 1 && a[j] > key)//Ѱ�Ҵ���key��ֵ
		{
      		a[j + 1] = a[j];//���ֵ
      		j--;
    	}
    	a[j + 1] = key;//��ֵΪkey, ���һ�β���
  	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	insertion_sort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

