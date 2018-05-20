#include <bits/stdc++.h>	//题目为链表的每k个元素逆置一次 
using namespace std;
typedef int Data;
typedef struct LinkList *Ptr;
typedef struct LinkList{
	Data data;
	Ptr next;
}LL;
void InputLL(Ptr &L1,int n);
Ptr Reverse(Ptr head,int k);
void OutputLL(Ptr L);

int main()	{
	Ptr L1=new LL;
	int n,k,cnt=0;
	cin >> n >> k;
	InputLL(L1,n);
	Ptr Lt=L1;
	while (n-cnt>=k)	{
		Lt->next=Reverse(Lt,k);
		for (int i=0;i<k&&Lt->next!=NULL;i++)	{
			Lt=Lt->next;
			cnt++;
		}
	}
	OutputLL(L1);
	return 0;
}

void InputLL(Ptr &L1,int n)	{
	int t;
	L1->next=new LL;
	Ptr L=L1->next;
	for (int i=0;i<n;i++)	{
		cin >> t;
		L->data=t;
		if (i<n-1)	{
			L->next=new LL;
			L=L->next;
		}
		else L->next=NULL;
	}
}

void OutputLL(Ptr L)	{
	for (L=L->next;L!=NULL;)	{
		printf("%d ",L->data);
		L=L->next;
	}
	printf("\n");
}

Ptr Reverse(Ptr head,int k)	{
	int cnt=1;
	Ptr New=head->next,tmp;
	Ptr Old=New->next;
	while (cnt<k)	{
		tmp=Old->next;
		Old->next=New;
		New=Old;Old=tmp;
		cnt++;
	}
	head->next->next=Old;
	return New;
}

