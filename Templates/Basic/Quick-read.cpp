//���
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;

void read(int &r)
{
	int f = 1;//f�Ƿ��ű���
	r = 0;//��Ŀ��r��ֵΪ0
	char ch = getchar();//ch���뵥���ַ�
	while(ch < '0' || ch > '9')//��������
	{
		if(ch == '-') f = -1;//����
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')//������
	{
		r = (r << 3) + (r << 1) + (ch ^ 48);//λ����ӿ����, ��Ч��r = r * 10 + ch - '0'
		ch = getchar();
	}
	r = f * r;
}

int main()
{
	read(n);
	return 0;
}
