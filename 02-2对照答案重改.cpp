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
PP PolySum(PP a,PP b);
PP PolyMulti(PP a,PP b);
void print(PP a);

int main()	{
	PP a,b,sum,mul;
	a=scan();
	b=scan();
	sum=PolySum(a,b);
	mul=PolyMulti(a,b);
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

PP PolySum(PP a,PP b)	{
	PP a1=a->Next,b1=b->Next;
	PP sum=(PP)malloc(sizeof(Poly)),head;
	head=sum;
	while (a1!=NULL&&b1!=NULL)	{
		PP temp=(PP)malloc(sizeof(Poly));
		temp->Next=NULL;
		if (a1->exp>b1->exp)	{
			temp=a1;
			sum->Next=temp;
			sum=sum->Next;
			a1=a1->Next;
		}
		else if (b1->exp>a1->exp)	{
			temp=b1;
			sum->Next=temp;
			sum=sum->Next;
			b1=b1->Next;
		}
		else	{
			int newcoe=a1->coe+b1->coe;
			if (newcoe==0)	{
				a1=a1->Next;
				b1=b1->Next;
			}
			else	{
				temp->coe=newcoe;
				temp->exp=a1->exp;
				sum->Next=temp;
				sum=sum->Next;
				a1=a1->Next;
				b1=b1->Next;
			}
		}
	}
	if (a1!=NULL)	sum->Next=a1;
	else if (b1!=NULL)	sum->Next=b1;
	return head;
}

PP PolyMulti(PP a,PP b)	{
	PP multisum=(PP)malloc(sizeof(Poly));
	PP a1=a->Next,b1=b->Next;
	PP a0=a1,b0=b1;
	PP temp=(PP)malloc(sizeof(Poly));
	multisum->Next=NULL;
	for (;a1!=NULL;a1=a1->Next)	{
		for (;b1!=NULL;b1=b1->Next){
			PP t=(PP)malloc(sizeof(Poly));
			t->coe=a1->coe*b1->coe;
			t->exp=a1->exp+b1->exp;
			t->Next=NULL;
			temp->Next=t;
			multisum=PolySum(multisum,temp); 
		}
		b1=b0;
	}
	return multisum;
}

void print(PP a)	{
	a=a->Next;
	int f=0;
	while (a)	{
		if (a->coe!=0)	{
			f=1;
			printf("%d %d",a->coe,a->exp);
			if (a->Next!=NULL) printf(" ");
        	else if (a->Next==NULL)    printf("\n");
		}
		a=a->Next;
	}
	if (f==0)	printf("0 0\n");
}

