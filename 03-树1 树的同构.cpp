#include <iostream>
#include <algorithm>
#include <memory.h>
#define MaxTree 10
#define Tree int
#define ElementType char
#define Null -1
using namespace std;

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[])	{			//输入字符那部分我调试了很长时间，scanf输入字符时
	int n;										//前面如果已经有scanf了，一定记得加getchar消除空字符！
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++){
		scanf("%c %c %c",&T[i].Element,&T[i].Left,&T[i].Right);
		getchar();
	}
	for (int i=0;i<n;i++)	{
		if (T[i].Left>='0'&&T[i].Left<='9')
			T[i].Left=T[i].Left-'0';
		if (T[i].Right>='0'&&T[i].Right<='9')
			T[i].Right=T[i].Right-'0';
		if (T[i].Left=='-')	T[i].Left=-1;
		if (T[i].Right=='-')	T[i].Right=-1;
	}
	int point[n],root;
	memset(point,0,sizeof(point));
	for (int i=0;i<n;i++)	{
		point[T[i].Left]=1;
		point[T[i].Right]=1;
	}
	for (int i=0;i<n;i++)	{
		if (point[i]==0)	{
			root=i;
			break;
		}
		else
			root=-1;
	} 
	return root;
}
bool IsEqual(Tree t1,Tree t2)	{	//递归的逻辑结构我理解的不够清晰啊，我到现在还是不太明白，接着看！ 
	if ((t1==Null)&&(t2=Null))		//如果两树为空，视为同构
		return true;
	if ((t1==Null&&t2!=Null)||(t1!=Null&&t2==Null))		//如果一个空一个不空，视为不同构 
		return false;
	if (T1[t1].Element!=T2[t2].Element)					//如果两树中节点数据不同，肯定不同构 
		return false;
	if ((T1[t1].Left==Null)&&(T2[t2].Left==Null))		//如果两树左子树为空，就处理他们的右子树 
		return IsEqual(T1[t1].Right,T2[t2].Right);
	if (((T1[t1].Left!=Null)&&(T2[t2].Left!=Null))&&
		((T1[T1[t1].Left].Element)==(T2[T2[t2].Left].Element)))		//如果两树左子树都不空，并且左子树指向的节点数据相等， 
			return (IsEqual(T1[t1].Left,T2[t2].Left)&&				//就继续分别处理当前节点的左子树，右子树 
					IsEqual(T1[t1].Right,T2[t2].Right));
	else
		return (IsEqual(T1[t1].Left,T2[t2].Right)&&					//上述情况都不成立时，左右比较 
				IsEqual(T1[t1].Right,T2[t2].Left)); 
}

int main()	{
	Tree t1,t2;
	t1=BuildTree(T1);
	t2=BuildTree(T2);
	if (IsEqual(t1,t2))	printf("Yes\n");
	else	cout << "No" <<endl;
	return 0;
}
