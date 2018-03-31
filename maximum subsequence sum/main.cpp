#include <iostream>
#include <algorithm>
#define N 1005
using namespace std;
int Maxsubsequencesum1(int List[],int n);   //暴力法，复杂度o(n^3)
int Maxsubsequencesum2(int List[],int n);   //利用每一次的加和，复杂度o(n^2)
int Maxsubsequencesum3(int List[],int n);   //分治法，复杂度o(nlogn)。这里的函数为接口，为了统一函数的格式，这样定义。
int DAC(int List[],int left,int right);     //及时处理法，复杂度o(n)，但是想出来不容易。
int Maxsubsequencesum4(int List[],int n);
int max3(int a,int b,int c) {return max(a,max(b,c));}   //比较三个数大小的函数
int main()  {
    int List[N]={1,2,3,4,5,6};
    cout << Maxsubsequencesum3(List,6) << endl;
    return 0;
}

int Maxsubsequencesum1(int List[],int n)    {
    int i,j,k,thissum,maxi=0;
    for (i=0;i<n;i++)   {
        for (j=i;j<n;j++)   {
            thissum=0;
            for (k=i;k<=j;k++)   {
                thissum+=List[k];
                if (maxi<thissum)
                    maxi=thissum;
            }
        }
    }
    return maxi;
}

int Maxsubsequencesum2(int List[],int n)    {
    int i,j,thissum,maxi=0;
    for (i=0;i<n;i++)   {
        thissum=0;
        for (j=i;j<n;j++)   {
            thissum+=List[j];
            if (maxi<thissum)
                maxi=thissum;
        }
    }
    return maxi;
}

int Maxsubsequencesum3(int List[],int n)    {return DAC(List,0,n-1);}   //接口标准化
int DAC(int List[],int left,int right)  {
    int MLS,MRS;
    int mid=(left+right)/2;
    int MLBS,MRBS;
    int LBS,RBS;
    if (left==right)   {        //递归的边界条件，达到时终止递归
        if (List[left]>0)   return List[left];
        else return 0;
    }
    MLS=DAC(List,left,mid);     //这两行
    MRS=DAC(List,mid+1,right);  //一直想不到，光理解都花了很久，更不用说想到了
    MLBS=0,LBS=0;   //求中轴左侧子序列的最大和
    for (int i=left;i<=mid;i++)  {
        LBS+=List[i];
        if (LBS>MLBS)
            MLBS=LBS;
    }
    MRBS=0,RBS=0;   //求中轴右侧子序列的最大和
    for (int i=mid+1;i<=right;i++)  {
        RBS+=List[i];
        if (RBS>MRBS)
            MRBS=RBS;
    }
    return max3(MLS,MRS,MLBS+MRBS);
}

int Maxsubsequencesum4(int List[],int n)    {
    int maxi=0,sum=0;
    for (int i=0;i<n;i++)   {
        sum+=List[i];
        if (maxi<sum)
            maxi=sum;
        else if (sum<0)
            sum=0;
    }
}
