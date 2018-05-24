#include <bits/stdc++.h>
#define MaxVertexNum 100
using namespace std;
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight; 
};
typedef PtrToENode Edge;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv,Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;
typedef int Vertex;
LGraph CreateGraph(int VertexNum)	{
	LGraph Graph;
	Graph=(LGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for (int i=0;i<Graph->Nv;i++)
		Graph->G[i].FirstEdge=NULL;
	return Graph;
}
void InsertGraph(LGraph Graph,Edge E)	{
	PtrToAdjVNode NewNode;
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge=NewNode;
	//由于是无向图，所以需要将上述代码复制一遍，把V1和V2交换位置
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V1;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge=NewNode;
}
LGraph BuildGraph()	{
	LGraph Graph;
	int Nv,Ne;
	scanf("%d %d",&Nv,&Ne);
	Graph=CreateGraph(Nv);
	Graph->Ne=Ne;
	if (Ne)	{
		Edge E=(Edge)malloc(sizeof(struct ENode));
		for (int i=0;i<Graph->Ne;i++)	{
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertGraph(Graph,E);
		}
	}
	return Graph; 
}
int main()	{
	return 0;
}
