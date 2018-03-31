#include <iostream>
#include <algorithm>
#include <stack>
#define N 1003
using namespace std;
int main()	{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	while (k--)	{
		int aim[N],i=1,j=1;
		stack<int> st;
		for (int ii=1;ii<=n;ii++)
			scanf("%d",&aim[ii]);
		while (1)	{
			if (st.empty())	{st.push(j);j++;}
			else if (!st.empty()&&st.top()==aim[i])	{st.pop();i++;}
			else	{st.push(j);j++;}
			if (i>n)	{printf("YES\n");break;}
			else if (st.size()>=m)	{
				if (st.top()!=aim[i])	{
					printf("NO\n");
					break;
				}
			}
		}
	}
	return 0;
}
