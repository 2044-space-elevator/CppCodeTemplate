//�߶���ά������� �����޸� �����ѯ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll n, a[N], d[N << 2];//a��ԭ����, d�Ǵ��߶���������

void build(ll l, ll r, ll p)//����
{
	if(l == r)//Ҷ��, ֱ�Ӹ�ֵ
	{
		d[p] = a[l];
		return ;
	}
	ll mid = (l + r) >> 1;//ȡ�����е�
	build(l, mid, p << 1);//�ݹ齨������, p << 1��ʾp * 2,Ϊ������
	build(mid + 1, r, p << 1 | 1);//�ݹ齨������, p << 1 | 1��ʾp * 2 + 1, Ϊ������
	d[p] = d[p << 1] + d[p << 1 | 1];//����������
}

void update(ll p, ll l, ll r, ll pos, ll v)//�����޸�
{
	if(l == r && l == pos)//����Ŀ��λ��
	{
		d[p] = v;
		return ;
	}
	ll mid = (l + r) >> 1;//ȡ�����е�
	if(pos <= mid) update(p << 1, l, mid, pos, v);//Ŀ����������
	else update(p << 1 | 1, mid + 1, r, pos, v);//Ŀ����������
	d[p] = d[p << 1] + d[p << 1 | 1];//����������
}

ll query(ll p, ll l, ll r, ll ql, ll qr)//�����ѯ, l, rΪ��ǰ����, ql, qrΪĿ������
{
	if(ql <= l && qr >= r) return d[p];//����Ҷ�ӽڵ�, ֱ�ӷ���ֵ
	ll mid = (l + r) >> 1, res = 0;//ȡ�����е�
	if(ql <= mid) res += query(p << 1, l, mid, ql, qr);//��������ȫ������һ��������������, ������������ѯ
	if(qr >= mid + 1) res += query(p << 1 | 1, mid + 1, r, ql, qr);//��������ȫ������һ��������������, ������������ѯ
	return res;//�ۼ�
}

int main()
{
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++)//����ԭ����
	{
		scanf("%lld", a + i);
	}
	build(1, n, 1);//����
	//update(1, 1, n, 2 ,4);//��λ��2��ֵ�޸�Ϊ4
	//query(1, 1, n, 2, 4);//��ѯ2~4�������
	return 0;
}
