#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DNode
{
    struct DNode* prior;
    struct DNode* next;
    int data;
}DNode;

void PrintNumberOfQuestion(int i)
{
    printf("\n-----------------No %d----------------------\n",i);
}

void GetNumber()
{
    PrintNumberOfQuestion(1);
    
    // 建立数组存放10个整数
    int a[10] = {0};

    double average = 0;
    int position[2];
    int i = 0;

    while(i < 10)
    {
        scanf("%d",&a[i]);
        i++;
    }

    int sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum += a[i];
    }
    average = (sum * 1.0) / 10;

    double flag = INT_MAX;
    for (i = 0; i < 10; i++)
    {
        double distance = a[i] - average >= 0 ? a[i] - average : -a[i] + average;
        if (distance < flag)
        {
            flag = distance;
            position[0] = a[i];
            position[1]= i;
        }
    }

    printf("res is %d\n", position[0]);

}

void OutputPrime()
{
    PrintNumberOfQuestion(2);
    for (int i = 2001; i <= 2016; i++)
    {
        int j = 2;

        for (; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }

        if (j >= i)
        {
            printf("%d\t", i);
        }

    }
}

int RecursionGetNum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * RecursionGetNum(n - 1);
}

void PrintfFib()
{
    int n = 0;
    PrintNumberOfQuestion(4);
    scanf("%d", &n);
    printf("res is %d", RecursionGetNum(2*n));
}

DNode* CreateDNList()
{
    DNode* head = (DNode*)malloc(sizeof(DNode));
    head->prior = head;
    head->next = head;
    DNode* tail;
    DNode* pre;
    pre = tail = head;
    int a = -1;

    while (a != 0)
    {
        DNode* cur = (DNode*)malloc(sizeof(DNode));
        cur->data = a;
        tail->next = cur;
        cur->prior = pre;
        
        tail = cur;
        pre = tail->prior;

        scanf("%d", &a);
        
    }
    tail->next = head;
    tail->next->prior = tail;
    
    return head;
}

void Traverse(DNode* head)
{
    PrintNumberOfQuestion(5);
    printf("正向遍历输出链表-->\n");

    DNode* dummy = head;
    while(dummy->next != head)
    {
        printf("%d\t",dummy->data);
        dummy = dummy->next;
    }

    printf("反向遍历输出链表-->\n");
    dummy = head;
    while (dummy->prior != head)
    {
        printf("%d\t",dummy->data);
        dummy = dummy->prior;
    }   
}

int main()
{
    return 0;
}