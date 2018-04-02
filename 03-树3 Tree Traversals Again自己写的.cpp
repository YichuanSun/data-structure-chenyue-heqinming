#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct TreeNode *PTN;
typedef struct TreeNode{
	int Data;
	PTN Left;
	PTN Right;
}BinTree;
int top=-1,num=0;
int ans[32];
PTN Stack[32];			//模拟栈
void Pop()	{			//删除栈顶元素 
	top--;
}
void Push(PTN t)	{	//在栈顶压入一个元素 
	Stack[++top]=t;
}
PTN Top()	{
	return Stack[top];
}
void PostorderTraversalSequence(PTN root)	{
	if (!root)	return;
	else	{
		PostorderTraversalSequence(root->Left);
		PostorderTraversalSequence(root->Right);
		ans[num++]=root->Data;
	}
}
int main()	{
	int n;
	int findroot=0,perpop=0;
	PTN root,father;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)	{
		char act[7];
		scanf("%s",act);
		if (strcmp(act,"Push")==0)	{
			int temp;
			PTN NewP=(PTN)malloc(sizeof(BinTree));
			scanf("%d",&temp);
			NewP->Data=temp;
			NewP->Left=NewP->Right=NULL;
			if (!findroot)	{		//寻找是否有根节点。为什么要有这一步呢？ 
				root=NewP;
				findroot=1;
				Push(NewP);
			}
			else {
				if (perpop==0)
					father=Top();
				if (father->Left==NULL)	father->Left=NewP;
				else if (father->Right==NULL)	father->Right=NewP;
				Push(NewP);
				perpop=0;
			}
		}
		else	{
			father=Top();
			Pop();
			perpop=1;
		}
	}
	PostorderTraversalSequence(root);
	for (int i=0;i<num;i++)	{
		printf("%d",ans[i]);
		if (i!=num-1)	printf(" ");
		else	printf("\n");
	}
	return 0;
}
