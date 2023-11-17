//�߶���ά������� �����޸� �����ѯ
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e5 + 5;
LL n, a[N], d[N << 2];//a��ԭ����, d�Ǵ��߶���������

void build(LL l, LL r, LL p)//����
{
	if(l == r)//Ҷ��, ֱ�Ӹ�ֵ
	{
		d[p] = a[l];
		return ;
	}
	LL mid = (l + r) >> 1;//ȡ�����е�
	build(l, mid, p << 1);//�ݹ齨������, p << 1��ʾp * 2,Ϊ������
	build(mid + 1, r, p << 1 | 1);//�ݹ齨������, p << 1 | 1��ʾp * 2 + 1, Ϊ������
	d[p] = d[p << 1] + d[p << 1 | 1];//����������
}

void update(LL p, LL l, LL r, LL pos, LL v)//�����޸�
{
	if(l == r && l == pos)//����Ŀ��λ��
	{
		d[p] = v;
		return ;
	}
	LL mid = (l + r) >> 1;//ȡ�����е�
	if(pos <= mid) update(p << 1, l, mid, pos, v);//Ŀ����������
	else update(p << 1 | 1, mid + 1, r, pos, v);//Ŀ����������
	d[p] = d[p << 1] + d[p << 1 | 1];//����������
}

LL query(LL p, LL l, LL r, LL ql, LL qr)//�����ѯ, l, rΪ��ǰ����, ql, qrΪĿ������
{
	if(ql <= l && qr >= r) return d[p];//����Ҷ�ӽڵ�, ֱ�ӷ���ֵ
	LL mid = (l + r) >> 1, res = 0;//ȡ�����е�
	if(ql <= mid) res += query(p << 1, l, mid, ql, qr);//��������ȫ������һ��������������, ������������ѯ
	if(qr >= mid + 1) res += query(p << 1 | 1, mid + 1, r, ql, qr);//��������ȫ������һ��������������, ������������ѯ
	return res;//�ۼ�
}

int main()
{
	scanf("%lld", &n);
	for(LL i = 1; i <= n; i++)//����ԭ����
	{
		scanf("%lld", a + i);
	}
	build(1, n, 1);//����
	//update(1, 1, n, pos,v);//��λ��pos��ֵ�޸�Ϊv
	//query(1, 1, n, l, r);//��ѯl~r�������
	return 0;
}
