#include <bits/stdc++.h>
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
	Vertex v1,v2;
	WeightType Weight; 
};
typedef PtrToGNode MGraph;		//��ʾ����һ��ָ��matrixͼ��ָ��
typedef PtrToENode Edge;	//ָ��ߵ�ָ��
MGraph CreatGraph(int VertexNum)	{
	Vertex V,M;
	MGraph Graph;
	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for (V=0;V<Graph->Nv;V++)
		for (W=0;W<Graph->Nv;W++)
			Graph->G[V][M]=0;
	return Graph;
}
void InsertNode(MGraph Graph,Edge E)	{
	Graph->G[E->v1][E->v2]=E->Weight;
	Graph->G[E->v2][E->v1]=E->Weight;
}
int main()	{
	
	return 0;
}
