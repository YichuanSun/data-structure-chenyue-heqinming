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

Tree BuildTree(struct TreeNode T[])	{			//�����ַ��ǲ����ҵ����˺ܳ�ʱ�䣬scanf�����ַ�ʱ
	int n;										//ǰ������Ѿ���scanf�ˣ�һ���ǵü�getchar�������ַ���
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
bool IsEqual(Tree t1,Tree t2)	{	//�ݹ���߼��ṹ�����Ĳ������������ҵ����ڻ��ǲ�̫���ף����ſ��� 
	if ((t1==Null)&&(t2=Null))		//�������Ϊ�գ���Ϊͬ��
		return true;
	if ((t1==Null&&t2!=Null)||(t1!=Null&&t2==Null))		//���һ����һ�����գ���Ϊ��ͬ�� 
		return false;
	if (T1[t1].Element!=T2[t2].Element)					//��������нڵ����ݲ�ͬ���϶���ͬ�� 
		return false;
	if ((T1[t1].Left==Null)&&(T2[t2].Left==Null))		//�������������Ϊ�գ��ʹ������ǵ������� 
		return IsEqual(T1[t1].Right,T2[t2].Right);
	if (((T1[t1].Left!=Null)&&(T2[t2].Left!=Null))&&
		((T1[T1[t1].Left].Element)==(T2[T2[t2].Left].Element)))		//������������������գ�����������ָ��Ľڵ�������ȣ� 
			return (IsEqual(T1[t1].Left,T2[t2].Left)&&				//�ͼ����ֱ���ǰ�ڵ���������������� 
					IsEqual(T1[t1].Right,T2[t2].Right));
	else
		return (IsEqual(T1[t1].Left,T2[t2].Right)&&					//���������������ʱ�����ұȽ� 
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
