//ð������
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N], n;

void bubble_sort()//Ĭ�ϴ�С��������
{
  	bool flag = 1;//flag��¼�����Ƿ��Ѿ�����
  	while(flag)//��flag == 0, ˵��û�н��н���, ��ô�����Ѿ�����
	{
    	flag = 0;
    	for(int i = 1; i < n; i++)
		{
    		if(a[i] > a[i + 1])//����Ԫ������
			{
	    	    flag = 1;
	    	    swap(a[i], a[i + 1]);//������������Ԫ��
      		}
    	}
  	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	bubble_sort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

