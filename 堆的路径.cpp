#include <bits/stdc++.h>
#define MAXN 1001
#define MINH -10001
using namespace std;
int H[MAXN],size;
void Creat()	{
	size=0;
	H[0]=MINH;
}
void Insert(int X)	{
	int i;
	for (i=++size;H[i/2]>X;i/=2)	{	//i/2表示下标i节点的父节点
		H[i]=H[i/2]; 
	}
	H[i]=X;
}
int main()	{
	int n,m,x,i;
	scanf("%d %d",&n,&m);
	Creat();
	for (i=0;i<n;i++)	{
		scanf("%d",&x);
		Insert(x);
	}
	for (i=0;i<m;i++)	{
		scanf("%d",&x);
		while(x)	{
			printf("%d",H[x]);
			cout << (x==1?'\n':' ');
			x/=2;
		}
	}
	return 0;
}
