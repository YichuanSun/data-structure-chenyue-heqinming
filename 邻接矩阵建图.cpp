#include <bits/stdc++.h>
#define MaxVertexNum 100
using namespace std;
typedef struct GNode *PtrToGNode;	//ָ��ͼ��ָ��
typedef struct ENode *PtrToENode;
typedef int Vertex;
typedef int WeightType;
struct GNode{		//��װͼ�ṹ
	int Nv;		//ͼ�Ľڵ���
	int Ne;		//ͼ�ı��� 
	WeightType G[MaxVertexNum][MaxVertexNum];	//�ڽӾ����ͼ
	//DataType Data[MaxVertexNum];	//�б�Ҫʱ�����洢�ڵ�������
};
struct ENode{
	Vertex V1,V2;
	WeightType Weight; 
};
typedef PtrToGNode MGraph;		//��ʾ����һ��ָ��matrixͼ��ָ��
typedef PtrToENode Edge;	//ָ��ߵ�ָ��
MGraph CreatGraph(int VertexNum)	{
	Vertex V,W;
	MGraph Graph;
	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for (V=0;V<Graph->Nv;V++)
		for (W=0;W<Graph->Nv;W++)
			Graph->G[V][W]=0;
	return Graph;
}
void InsertNode(MGraph Graph,Edge E)	{
	Graph->G[E->V1][E->V2]=E->Weight;
	Graph->G[E->V2][E->V1]=E->Weight;
}
MGraph BuildGraph()	{
	MGraph Graph;
	int Nv;
	scanf("%d",&Nv);
	Graph=CreatGraph(Nv);
	scanf("%d",&Graph->Ne);
	if (Graph->Ne!=0)	{
		Edge E=(Edge)malloc(sizeof(struct ENode));
		for (int i=0;i<Graph->Ne;i++)	{
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertNode(Graph,E);
		}
	}
	return Graph; 
}
int main()	{
	
	return 0;
}
