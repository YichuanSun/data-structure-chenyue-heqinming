#include <bits/stdc++.h>
#define SIZE 105
using namespace std;
int spot[SIZE];
typedef struct point{
	double x,y;
}point;
point coord[SIZE];
point zero;
int FirstJump(point pnt);
int dfs(point p);
int IsSave(point p);
double dis(point a,point b)	{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n,len;
double rad=15.0/2;
int main()	{
	zero.x=0,zero.y=0;
	int ans=0;
	scanf("%d %d",&n,&len);
	for (int i=0;i<n;i++)	scanf("%lf %lf",&coord[i].x,&coord[i].y);
	for (int i=0;i<n;i++)	{
		if (FirstJump(coord[i])&&!spot[i]){
			spot[i]=1;
			ans=dfs(coord[i]);
			if (ans)	break;
		}
	}
	if (ans)	printf("Yes\n");
	else printf("No\n");
	return 0;
}
int FirstJump(point pnt)	{
	if (dis(pnt,zero)>len+rad)	return 0;
	else return 1;
}
int dfs(point p)	{
	if (IsSave(p))	return 1;
	for (int i=0;i<n;i++)
		if (!spot[i]&&dis(p,coord[i])<=len){
			printf("%.2f",dis(p,coord[i]));
			dfs(coord[i]);
		}
	return 0;
}
int IsSave(point p)	{
	if (p.x-len<-50)	return 1;
	else if (p.x+len>50)		return 1;
	else if (p.y-len<-50)	return 1;
	else if (p.y+len>50)		return 1;
	else	return 0;
}


