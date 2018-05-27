#include <bits/stdc++.h>
using namespace std;
const int size=15;
typedef struct LNode *P;
typedef struct LNode{
	int data;
	P next;
}LNode;
void insert(int a,int b);
void dfs(int i);
void bfs(int i);
void DFS();
void BFS();
bool IsEdge(LNode graph[],P temp,int j);
LNode graph[size];
bool spot[size];
queue<P> que;
int n,m,ta,tb;
int main()	{
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)	graph[i].data=i;
	for (int i=0;i<m;i++){
		scanf("%d %d",&ta,&tb);
		insert(ta,tb);
		insert(tb,ta);
	}
	DFS(),memset(spot,false,sizeof(spot));
	BFS();
	return 0;
}
void insert(int a,int b){
	P NewNode=&graph[a];
	while (NewNode->next)	NewNode=NewNode->next;
	P TNode=(P)malloc(sizeof(LNode));
	TNode->next=NULL,TNode->data=b;
	NewNode->next=TNode;
}
void dfs(int i)	{
	P tep=graph[i].next;
	while (tep)	{
		if (!spot[tep->data])	{
			spot[tep->data]=1;
			printf("%d ",tep->data);
			dfs(tep->data);
		}
		tep=tep->next;
	}	
}
void bfs(int i)	{
	P tep=graph[i].next,temp;
	que.push(tep);
	spot[i]=1;
	while (!que.empty())	{
		temp=que.front();
		que.pop();
		for (int j=0;j<n;j++)	{
			if (!spot[j]&&IsEdge(graph,temp,j))	{	//temp，或者graph[j].next就是j所有相邻点的集合 
				printf("%d ",j);
				spot[j]=1;
				que.push(graph[j].next);		//相当于将j的所有邻接点加入队列 
			}
		}
	}
}
void DFS()	{//深搜 
	for	(int i=0;i<n;i++)	{
		if (!spot[i])	{
			spot[i]=1;
			printf("{ %d ",i);
			dfs(i);
			printf("}\n");
		}
	}
}
void BFS()	{
	for (int i=0;i<n;i++)	{
		if (!spot[i])	{
			printf("{ %d ",i);
			bfs(i);
			printf("}\n");
		}
	}
}
bool IsEdge(LNode graph[],P temp,int j)	{
	while (temp)	{
		if (temp->data==j)	return true;
		temp=temp->next;
	}
	return false;
}







