//这个程序出了问题，很可能是因为指向指针的指针的误用 
#include <stdio.h>
#include <stdlib.h>

typedef struct Poly *PP;
typedef struct Poly{
	int coe;	//系数 
	int exp;	//指数 
	PP Next; 
}Poly;
PP scan();
PP PolySum(PP a,PP b,PP sum);
PP PolyMuti(PP a,PP b,PP mul);
void print(PP a);

int main()	{
	PP a,b,sum,mul;
	sum=(PP)malloc(sizeof(Poly));
	mul=(PP)malloc(sizeof(Poly));
	a=scan();
	b=scan();
	sum=PolySum(a,b,sum);
	mul=PolyMuti(a,b,mul);
	print(sum);
	print(mul);
	return 0;
}
//输入链表 
PP scan()	{
	PP a=(PP)malloc(sizeof(Poly)),head;
	//a->Next=NULL;
	head=a;
	int n;
	scanf("%d",&n);
	while (n--)	{
		PP New=(PP)malloc(sizeof(Poly));
		scanf("%d %d",&New->coe,&New->exp);
		a->Next=New;
		a=a->Next;
	}
	a->Next=NULL;
	return head;
}

PP PolySum(PP a,PP b,PP sum)	{
	PP sum0=sum;
	while (a&&b)	{
		if (a->exp>b->exp)	{
			sum->Next=a;
			a=a->Next;
			PP New=(PP)malloc(sizeof(Poly));
			sum->Next=New;
			sum=sum->Next;
		}
		else if (b->exp>a->exp)	{
			sum=b;
			b=b->Next;
			PP New=(PP)malloc(sizeof(Poly));
			sum->Next=New;
			sum=sum->Next;
		}
		else	{
			int ssum=a->coe+b->coe;
			if (ssum!=0)	{
				PP temp=(PP)malloc(sizeof(Poly));
				temp->coe=ssum;
				temp->exp=a->exp;
				sum=temp;
				PP New=(PP)malloc(sizeof(Poly));
				sum->Next=New;
				sum=sum->Next;
				a=a->Next;
				b=b->Next;
			}
		}
	}
	if (a)	sum=a;
	else if (b)	sum=b;
	else	sum=NULL;
	//sum=sum0;
	return sum0;
}

PP PolyMuti(PP a,PP b,PP mul)	{
	
}

void print(PP a)	{
    while (a)  {
        printf("%d %d",a->coe,a->exp);
        if (a->Next!=NULL) printf(" ");
        else if (a->Next==NULL)    printf("\n");
        a=a->Next;
    }
}

