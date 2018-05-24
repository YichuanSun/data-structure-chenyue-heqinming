#include <bits/stdc++.h>
#define MaxVertexNum 100
using namespace std;
typedef struct GNode *PtrToGNode;	//指向图的指针
typedef struct ENode *PtrToENode;
typedef int Vertex;
typedef int WeightType;
struct GNode{		//封装图结构
	int Nv;		//图的节点数
	int Ne;		//图的边数 
	WeightType G[MaxVertexNum][MaxVertexNum];	//邻接矩阵存图
	//DataType Data[MaxVertexNum];	//有必要时用来存储节点内数据
};
struct ENode{
	Vertex V1,V2;
	WeightType Weight; 
};
typedef PtrToGNode MGraph;		//表示这是一个指向matrix图的指针
typedef PtrToENode Edge;	//指向边的指针
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
