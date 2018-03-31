#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

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

/* 你的代码将被嵌在这里 */
List Merge(List L1,List L2) {
    //由于链表头一般不存储信息，所以都取Next
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
    //当此时，由于L是一直移动的指针，所以它并不是链表头，只有它的初始值L0才是链表头。
    return L0;
}
