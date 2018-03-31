#include <iostream>
#include <algorithm>
#define N 1005
using namespace std;
int Maxsubsequencesum1(int List[],int n);   //�����������Ӷ�o(n^3)
int Maxsubsequencesum2(int List[],int n);   //����ÿһ�εļӺͣ����Ӷ�o(n^2)
int Maxsubsequencesum3(int List[],int n);   //���η������Ӷ�o(nlogn)������ĺ���Ϊ�ӿڣ�Ϊ��ͳһ�����ĸ�ʽ���������塣
int DAC(int List[],int left,int right);     //��ʱ���������Ӷ�o(n)����������������ס�
int Maxsubsequencesum4(int List[],int n);
int max3(int a,int b,int c) {return max(a,max(b,c));}   //�Ƚ���������С�ĺ���
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

int Maxsubsequencesum3(int List[],int n)    {return DAC(List,0,n-1);}   //�ӿڱ�׼��
int DAC(int List[],int left,int right)  {
    int MLS,MRS;
    int mid=(left+right)/2;
    int MLBS,MRBS;
    int LBS,RBS;
    if (left==right)   {        //�ݹ�ı߽��������ﵽʱ��ֹ�ݹ�
        if (List[left]>0)   return List[left];
        else return 0;
    }
    MLS=DAC(List,left,mid);     //������
    MRS=DAC(List,mid+1,right);  //һֱ�벻��������ⶼ���˺ܾã�������˵�뵽��
    MLBS=0,LBS=0;   //��������������е�����
    for (int i=left;i<=mid;i++)  {
        LBS+=List[i];
        if (LBS>MLBS)
            MLBS=LBS;
    }
    MRBS=0,RBS=0;   //�������Ҳ������е�����
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
