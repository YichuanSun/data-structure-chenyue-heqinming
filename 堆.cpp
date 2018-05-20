#include <bits/stdc++.h>
#define MaxData 100000000
using namespace std;
typedef int ElementType; 
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
	ElementType *Elements;
	int Size;
	int Capacity;
};
MaxHeap Create(int MaxSize)	{
	MaxHeap H=new HeapStruct;
	H->Elements=new ElementType[MaxSize+1];
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;
	return H;
}
void Insert(MaxHeap H,ElementType item)	{
	int i;
	if (IsFull(H))	{
		printf("��������\n");
		return;
	}
	i=++H->Size;
	for (;H->Elements[i/2]<item;i/=2)
		H->Elements[i]=H->Elements[i/2];
	H->Elements[i]=item;
} 
ElementType DeleteMax(MaxHeap H)	{
	int Parent,Child;
	ElementType MaxItem,temp;
	if (IsEmpty(H))	{
		printf("������Ϊ��\n");
		return;
	}
	MaxItem=H->Elements[1];
	temp=H->Elements[H->Size--];
	for (Parent=1;2*Parent<=H->Size;Parent=Child)	{
		Child=Parent*2;
		if (Child!=H->Size)&&	//������������������˵�����child����һ�����������
			(H->Elements[Child]<H->Elements[Child+1])	//��˵��ɾ��ĩ�ڵ�����child����ͬ���ڵ���ֵܽڵ㣬�Ϳ���ͨ���Ƚ��ҳ����� 
			Child++;
		if (temp>=H->Elements[Child])	break;
		else	H->Elements[Parent]=H->Elements[Child];
	}
	H->Elements[Parent]=temp;
	return MaxItem;
}
int main()	{
	int n;
	return 0;
}




