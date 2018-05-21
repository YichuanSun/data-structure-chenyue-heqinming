#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];
SetName Find(SetType S,ElementType X)	{
	for (;S[X]>=0;X=S[X]);
	return X;
}
void Union(SetType S,SetName Root1,SetName Root2)	{
	S[Root2]=Root1;
}
int main()	{
	SetType S;
	int n;
	char in;
	scanf("%d\n",&n);
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
	Root1=
}





