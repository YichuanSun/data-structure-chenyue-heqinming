/*
��Ŀʵ����ͨ�������������������������ٺ����������
����˼·
1. ͨ�����뽨��
    Push���������½�һ���ڵ㣬�����븸�ڵ����Ӳ�ͬʱѹջ
    Pop��������ջ������һ���ڵ�
2. ����������ݹ�ʵ��
*/ 
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define STR_LEN 5
#define MAX_SIZE 30

typedef struct Node		//����ڵ�����
{
    int data;
    struct Node *left, *right;
}* treeNode;

treeNode Stack[MAX_SIZE];	//
int values[MAX_SIZE];		//

int num = 0;
int top = -1;

void Push(treeNode tn);
treeNode Pop();
treeNode Top();
bool isEmpty();

void PostOrderTraversal(treeNode root);

int main()
{
    int n;
    char operation[STR_LEN];
    treeNode father, root;
    bool findRoot = 0, Poped = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%s", operation);
        if (strcmp(operation, "Push") == 0)
        {
            int value;
            scanf("%d", &value);
            treeNode newNode;
            newNode = (treeNode)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            if (!findRoot)
            {
                root = newNode;     //���ڵ�
                Push(newNode);
                findRoot = 1;
            }
            else
            {
                if (!Poped)     //���ǰһ����������pop���򸸽ڵ�Ϊջ��Ԫ��
                    father = Top();
                if (father->left == NULL)
                    father->left = newNode;
                else
                    father->right = newNode;
                //printf("%d\n", newNode->data);
                Push(newNode);
            }
            Poped = 0;
        }
        else
        {
            father = Pop();
            Poped = 1;
        }
    }
    PostOrderTraversal(root);
    for (int i = 0; i < num-1; i++)
        printf("%d ", values[i]);
    printf("%d\n", values[num-1])
    return 0;
}

void PostOrderTraversal(treeNode root)
{
    treeNode tn = root;
    if(tn)
    {
        PostOrderTraversal(tn->left);
        PostOrderTraversal(tn->right);
        values[num++] = tn->data;       //������������Ľڵ�ֵ����������ڸ�ʽ����ӡ
    }
}

void Push(treeNode tn)
{
    Stack[++top] = tn;
}

treeNode Pop()
{
    return Stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

treeNode Top()
{
    return Stack[top];
}
