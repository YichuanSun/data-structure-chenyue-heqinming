#include <iostream>
#include <algorithm>
using namespace std;

int main()	{
	
	return 0;
}

Position BinarySearch( List L, ElementType X )	{
	int i=0,low=0,high,mid,flag=0;
	high=L->Last;
	while (low<=high)	{
		mid=(low+high)/2;
		if (L->Data[mid]>X)
			high=mid-1;
		else if (L->Data[mid]<X)
			low=mid+1;
		else	{
			flag=1;
			break;
		}
	}
	if (flag)
		return mid;
	else
		return NotFound;
} 
