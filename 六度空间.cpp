#include <bits/stdc++.h>
using namespace std;
void insert(int a,int b);
typedef struct Node *PtoNode;
typedef struct Node{
	int data;
	PtoNode next;
}Node;
const int size=10005;
Node graph[size];
int main()	{
	int n,m,ta,tb;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)	{
		scanf("%d %d",&ta,&tb);
		insert(ta,tb);
		insert(tb,ta);
	}
	/*	´òÓ¡Í¼ 
	for (int i=1;i<=n;i++)	{
		PtoNode np=&(graph[i]);
		while (np)	{
			printf("%d	",np->data);
			np=np->next;
		}
		printf("\n");	
	}
	*/
	return 0;
} 
void insert(int a,int b)	{
	PtoNode NewP=&(graph[a]);
	NewP->data=a;
	while (NewP->next)	NewP=NewP->next;
	PtoNode newNode=(PtoNode)malloc(sizeof(Node));
	newNode->data=b;
	newNode->next=NULL;
	NewP->next=newNode; 
}




