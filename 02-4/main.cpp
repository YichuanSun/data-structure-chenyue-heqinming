//下面是静态链表的正解
#include <iostream>
#include <algorithm>
using namespace std;
struct SL{
    int data;
    int nex;
}SL[100000];

int main()  {
    int address0,data0,k;
    cin >> address0 >> data0 >> k;
    int dat=data0;
    while (dat--) {
        int ad,da,ne;
        cin >> ad >> da >> ne;
        SL[ad].data=da;
        SL[ad].nex=ne;
    }
    int List[100000];
    int p=address0,i=1;
    while (p!=-1) {
        List[i++]=p;
        p=SL[p].nex;
    }
    for (int j=1;j+k<=i;j+=k)
        reverse(List+j,List+j+k);
    int j=1;
    for (j=1;j<i-1;j++)
        printf("%05d %d %05d\n",List[j],SL[List[j]].data,List[j+1]);
    printf("%05d %d -1\n",List[j],SL[List[j]].data);
    return 0;
}

//下面这段代码思路是错的，我想用动态链表做，但是太难了，而且可能直接就写不出来。用静态链表就简单多了
/*
#include <iostream>
#include <algorithm>
using namespace std;
typedef int first;
typedef int next;
typedef struct LL *PtoLL;
typedef struct LL   {
    int des;
    int data;
    int nextdes;
    PtoLL Front;
    PtoLL Behind;
}LL;

int cmp(const void *a,const void *b){
    PtoLL aa=(PtoLL)a;
    PtoLL bb=(PtoLL)b;
    return (aa->data-bb->data);
}

int main()  {
    int des0,data0,nextdes0;
    scanf("%d %d %d",&des0,&data0,&nextdes0);
    PtoLL newL=(PtoLL)malloc(sizeof(LL)),head;
    newL->Front=NULL;
    head=newL;
    while (data0--) {
        int dest,datat,nextdest;
        scanf("%d %d %d",&dest,&datat,&nextdest);
        PtoLL newLt=(PtoLL)malloc(sizeof(LL));
        newLt->des=dest;
        newLt->data=datat;
        newLt->nextdes=nextdest;
        newLt->Front=newL;
        newL->Behind=newLt;
        newL=newL->Behind;
    }
    newL->Behind=NULL;
    newL=head->Behind;
    qsort(head,data0,sizeof(LL),cmp);
    while (newL!=NULL)
    {
        printf("%d %d %d\n",newL->des,newL->data,newL->nextdes);
        newL=newL->Behind;
    }
    return 0;
}
*/
