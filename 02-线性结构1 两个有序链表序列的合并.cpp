#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Merge(List L1,List L2) {
    //��������ͷһ�㲻�洢��Ϣ�����Զ�ȡNext
    List LL1=L1->Next,LL2=L2->Next;
    List L=(PtrToNode)malloc(sizeof(struct Node));
    List L0=L;
    while (LL1&&LL2)    {
        if (LL1->Data<=LL2->Data)   {
            L->Next=LL1;
            LL1=LL1->Next;
        }
        else    {
            L->Next=LL2;
            LL2=LL2->Next;
        }
        L=L->Next;
    }
    L->Next=NULL;
    if (LL1)    L->Next=LL1;
    else if (LL2)   L->Next=LL2;
    L1->Next=NULL;
    L2->Next=NULL;
    //����ʱ������L��һֱ�ƶ���ָ�룬����������������ͷ��ֻ�����ĳ�ʼֵL0��������ͷ��
    return L0;
}
