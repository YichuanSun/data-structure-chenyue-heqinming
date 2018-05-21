#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];
/* 原版find代码 
SetName Find(SetType S,ElementType X)	{
	for (;S[X]>=0;X=S[X]);
	return X;
}*/
//下面是改进后的find 
SetName Find(SetType S,ElementType X)	{
	if (S[X]<0)	return X;
	else return S[X]=Find(S,S[X]);
}
void Union(SetType S,SetName Root1,SetName Root2)	{	//隐含了递归的思想，获得堆的高度 
	if (S[Root2]<S[Root1])	S[Root1]=Root2;
	else 	{
		if (S[Root2]==S[Root1])	S[Root1]--;
		S[Root2]=Root1;
	}
}
void Initialization(SetType S,int n)	{
	for (int i=0;i<MAXN;i++)	S[i]=-1;
}
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);
int main()	{
	SetType S;
	int n;
	char in;
	scanf("%d",&n);
	Initialization(S,n);
	do	{
		scanf("%c",&in);
		switch(in)	{
			case 'I':	Input_connection(S);break;
			case 'C':	Check_connection(S);break;
			case 'S':	Check_network(S,n);break;
		}
	}while (in!='S');
	return 0;
}
void Input_connection(SetType S)	{
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d",&u,&v);
	Root1=Find(S,u-1);
	Root2=Find(S,v-1);
	if (Root1!=Root2)	Union(S,Root1,Root2);
}
void Check_connection(SetType S)	{
	ElementType u,v;
	scanf("%d %d",&u,&v);
	SetName Root1,Root2;
	Root1=Find(S,u-1);
	Root2=Find(S,v-1);
	if (Root1==Root2)	printf("yes\n");
	else	printf("no\n");
}
void Check_network(SetType S,int n)	{
	int cnt=0;
	for (int i=0;i<n;i++)	{
		if (S[i]<0)	cnt++;
	}
	if (cnt==1)	printf("The network is connected.\n");
	else printf("There are %d components.\n",cnt);
}




