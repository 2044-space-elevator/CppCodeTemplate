//����ɸ��ɸ����
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;

bool vis[N];
ll pri[N], cnt;

void init(ll n)//����ɸ��ɸ����
{
	vis[0] = vis[1] = 1;
	for(ll i = 2; i <= n; i++)
	{
		if(!vis[i]) pri[cnt++] = i;
		for(ll j = 0; j < cnt; j++)
		{
			if(1ll * i * pri[j] > n) break;
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	return ;
}

int main()
{
	ll ed = 1000000ll;//ed��ɸ�������Ͻ�
	init(ed);
	for(ll i = 1; i <= min(N, ed); i++)//���ɸ��������
	{
		if(!vis[i]) printf("%lld ", i);
	}
	return 0;
}
