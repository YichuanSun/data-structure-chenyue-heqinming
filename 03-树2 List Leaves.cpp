#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef int ElemType;
typedef int PBT;
typedef struct BinTree	{
	ElemType Data;
	PBT Left;
	PBT Right;
}BinTree;
BinTree BT[11];
int point[11];
int remind[11];
int te;
void Traverse(int i);
int main()	{
	int n,i=0;
	scanf("%d",&n);
	while (n--)	{
		char t1,t2;
		BT[i].Data=i;
		scanf(" %c %c",&t1,&t2);
		if (t1=='-')	BT[i].Left=-1;
		else 	{
			BT[i].Left=t1-'0';
			point[BT[i].Left]=1;
		}
		if (t2=='-')	BT[i].Right=-1;
		else 	{
			BT[i].Right=t2-'0';
			point[BT[i].Right]=1;
		}
		i++;
	}
	int j=0;
	while (point[j++]);	//j-1就是根节点位置
	
	Traverse(j-1);
	for (int i=0;i<te;i++)	{
		printf("%d",remind[i]);
		if (i!=te-1)	printf(" ");
		else printf("\n");
	}
	return 0;
}

void Traverse(int i)	{	//层序遍历需要用队列 
	queue<int> Q;
	Q.push(i);
	while (!Q.empty())	{
		int temp=Q.front();
		if (BT[temp].Left==-1&&BT[temp].Right==-1)
			remind[te++]=temp;
		if (BT[temp].Left!=-1)	Q.push(BT[temp].Left);
		if (BT[temp].Right!=-1)	Q.push(BT[temp].Right);
		Q.pop();
	}
}




