#include <bits/stdc++.h>
using namespace std;
//�����Ǽ��ϵı�ʾ������ʵ����һ������ 
typedef struct	{
	ElementType data;
	int Parent;
}SetType;
typedef int SetName;
Setname OldFind(SetType S[],ElementType X)	{
	int i;
	for (i=0;i<MaxSize&&S[i].Data!=X;i++);
	if (i>=MaxSize)	return -1;
	for (;S[i].Parent>=0;i=S[i].Parent);
	return i;
}
SetName Find(SetType S,ElementType X)	{
	for (;S[X]>=0;X=S[X]);
	return X;
}
int main()	{
	
	return 0;
} 
