//递归实现数组求和
#include <iostream>
#define N 1005
using namespace std;
int s1,s2;
int n=19;
int dichotomysum(int a[],int lo,int hi);
int elasticsum(int a[],int lo,int hi);
void rearrange(int a[],int lo,int hi);
void rearrange(int a[],int n);
int main()  {
    int a[N];
    for (int i=0;i<20;i++)  a[i]=i;
    s1=dichotomysum(a,0,n);
    s2=elasticsum(a,0,n);
    cout << s1 <<endl;
    cout << s2 <<endl;
    rearrange(a,0,n);
    for (int i=0;i<n;i++)  printf("%d\n",a[i]);
    return 0;
}

//此为二分递归
int dichotomysum(int a[],int lo,int hi) {
    int mid=(lo+hi)/2;
    if  (lo>=hi)    //平凡条件
        return a[mid];
    else            //一般情况，递归形式下的操作
        return dichotomysum(a,lo,mid)+dichotomysum(a,mid+1,hi);
}

//此为线性递归
int elasticsum(int a[],int lo,int hi)   {
    if (lo>hi)
        return 0;
    else
        return elasticsum(a,lo+1,hi)+a[lo];
    return 0;
}
//数组逆序排列
void rearrange(int a[],int lo,int hi)    {
    if (lo<hi) {
    swap(a[lo],a[hi]);
    rearrange(a,lo+1,hi-1);
    }
}

void rearrange(int a[],int n)    {   //接口函数
    rearrange(a,0,n-1);}
