#include <bits/stdc++.h>
using namespace std;
const int size=15;
typedef struct LNode *P;
typedef struct LNode{
	int data;
	P next;
}LNode;
void insert(int a,int b);
LNode graph[size];
int main()	{
	int n,m,ta,tb;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d %d",&ta,&tb);
		insert(ta,tb);
		insert(tb,ta);
	}
	for (int i=0;i<n;i++)	{
		P np=graph[i].next;
		while (np)	{
			printf("%d	",np->data);
			np=np->next;
		}
		printf("\n");	
	}
	return 0;
}
void insert(int a,int b){
	P NewNode=&graph[a];
	while (NewNode->next)	NewNode=NewNode->next;
	P TNode=(P)malloc(sizeof(LNode));
	TNode->next=NULL,TNode->data=b;
	NewNode->next=TNode;
}
