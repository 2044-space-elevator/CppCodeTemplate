//����ɸ��ɸ����
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e5 + 5;

bool vis[N];
LL pri[N], cnt;

void init(LL n)//����ɸ��ɸ����
{
	vis[0] = vis[1] = 1;
	for(LL i = 2; i <= n; i++)
	{
		if(!vis[i]) pri[cnt++] = i;
		for(LL j = 0; j < cnt; j++)
		{
			if(1LL * i * pri[j] > n) break;
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	return ;
}

int main()
{
	LL ed = 1000000ll;//ed��ɸ�������Ͻ�
	init(ed);
	for(LL i = 1; i <= min(N, ed); i++)//���ɸ��������
	{
		if(!vis[i]) printf("%lld ", i);
	}
	return 0;
}
