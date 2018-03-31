#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int main()	{
	int a[N],n,n1,i=0,max=-100000,t=0;
	scanf("%d",&n);
	n1=n;
	while (n1--)	{scanf("%d",&a[i++]);}
	for (i=0;i<n;i++)	{
		t+=a[i];
		if (t>max)	max=t;
		if (t<0)	t=0;
	}
	printf("%d\n",max);
}
