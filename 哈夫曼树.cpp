#include <bits/stdc++.h>
#define N 100000000
using namespace std;
typedef struct TreeNode *HuffmanTree;
struct TreeNode{
	int Weight;
	HuffmanTree Left,Right;
};
HuffmanTree Huffman(MinHeap H)	{
	int i;HuffmanTree T;
	BuildMinHeap(H);
	for (int i=0;i<H->Size;i++)	{
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left=DeleteMin(H);
		T->Right=DeleteMin(H);
		T->Weight=T->Left->Weight+T->Right->Weight;
		Insert(H,T);
	}
	T=DeleteMin(H);
	return T;
}
int main()	{
	
	return 0;
}
