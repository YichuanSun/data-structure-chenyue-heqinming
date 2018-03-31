#include <iostream>
#include <algorithm>
#define N 10005
using namespace std;

int main()	{
	int i,n,a[N],low=0,high=0,max=-1,sum=0,t=0,flag=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)	{scanf("%d",&a[i]);}
	for (i=0;i<n;i++)	{
		sum+=a[i];
		if (sum>max)	{		//说明序列中存在正数
			high=i;
			max=sum;
			low=t;
			flag=1;
		}
		if (sum<0)	{
			sum=0;
			t=i+1;
		}
	}
	if (flag==0)
		printf("%d %d %d\n",0,a[0],a[n-1]);
	else
		printf("%d %d %d\n",max,a[low],a[high]);
	return 0;
}
