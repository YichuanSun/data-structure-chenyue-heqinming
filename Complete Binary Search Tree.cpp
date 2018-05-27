#include <bits/stdc++.h>
#define SIZE 1005
using namespace std;
void solve(int res[],int root,int ans[]);
int n,res[SIZE],ans[SIZE],des=0;
int main()	{
	scanf("%d",&n);
	for (int i=0;i<n;i++)	scanf("%d",&res[i]);
	sort(res,res+n);
	solve(res,1,ans);
	printf("%d",ans[1]);
	for (int i=2;i<=n;i++)	printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
//建树的过程，相当于一个中序遍历 
void solve(int res[],int root,int ans[])	{
	if (root<=n)	{
		solve(res,root*2,ans);
		ans[root]=res[des++];
		solve(res,root*2+1,ans);
	}
}
