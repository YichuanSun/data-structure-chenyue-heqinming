#include <iostream>
#define N 1005
using namespace std;
int power(int a,int n);
int main()  {
    int n,a,ans;
    scanf("%d%d",&a,&n);
    ans=power(a,n);
    printf("%d^%d=%d",a,n,ans);
    return 0;
}

int power(int a,int n)  {
    if (n==0)    return 1;
    else
        return a*power(a,n-1);
}
