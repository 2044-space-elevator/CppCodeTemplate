//Dijkstra�����·,��ƫ��ά��
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5, M = 2e5 + 5;

ll dis[N], val[N], ver[M], ls[M], rs[M], dep[M], rt, book[N], cnt;
ll tot = -1, head[N];
ll n, m, s;

struct Edge
{
	ll ne, to, w;
}e[N << 1];//e���

void add(ll u, ll v, ll w)//�ӱ�
{
	++tot;
	e[tot].to = v, e[tot].w = w, e[tot].ne = head[u], head[u] = tot;
}

ll merge(ll x, ll y)//��ƫ����merge����
{
	if(!x || !y) return x + y;
	if(val[y] < val[x]) swap(x, y);
	rs[x] = merge(rs[x], y);
	if(dep[ls[x]] < dep[rs[x]]) swap(ls[x], rs[x]);
	dep[x] = dep[rs[x]] + 1;
	return x;
}

void dijkstra(ll s)//���·
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	val[++cnt] = 0;
	ver[cnt] = s;
	rt = merge(0, cnt);
	while(rt)
	{
		while(rt && book[ver[rt]])
		{
			rt=merge(ls[rt], rs[rt]);
		}
		if(rt == 0) break;
		ll u = ver[rt];
		book[u] = 1;
		for(ll i = head[u]; ~i; i = e[i].ne)//����u�ĳ���, �˴���~i�ж�head[i]�Ƿ�Ϊ-1(��)
		{
			ll v = e[i].to;
			if(book[v]) continue;
			if(dis[v] > dis[u] + e[i].w)//�ɳ�
			{
				dis[v] = dis[u] + e[i].w;
				val[++cnt] = dis[v];
				ver[cnt] = v;
				rt = merge(rt, cnt);
			}
		}
	}
	return ;
}

int main()
{
	memset(head, -1, sizeof(head));//�����ʼ��Ϊ-1, ��ֹ�ڴ��ȡʱ����
	scanf("%lld%lld%lld", &n, &m, &s);//�������n, ����m, Դ��s
	for(ll i = 1; i <= m; i++)//�����
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		add(u, v, w);
	}
	dijkstra(s);
	for(ll i = 1; i <= n; i++)//������㵽s�ľ���
	{
		printf("%lld ", dis[i]);
	}
	return 0;
}
