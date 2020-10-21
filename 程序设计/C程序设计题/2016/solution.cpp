#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void PrintfOrderOfProblems(int i)
{
    printf("\n----------------------%d------------------------\n",i);
}

void SortNumWithList()
{
    // 头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = nullptr;

    Node* p = head->next;    // 遍历结点
    Node* pre = head;    // 之前的结点

    int data;
    PrintfOrderOfProblems(5);
    while(scanf("%d", &data) != EOF && (data - '@') != 0)
    {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->data = data;

        // 如果空链表的话直接插入
        if(head->next == nullptr)
        {
            cur->next = head->next;
            head->next = cur;
        }
        else
        {
            p = head->next;
            pre = head;
            
            while(p != nullptr)
            {
                // 找到第一个比输入数据大的结点
                if (p->data >= cur->data)
                {
                    pre->next = cur;
                    cur->next = p;
                    break;
                }
                p = p->next;
                pre = pre->next;
            }
            // 没找到比他小的，则放在最后
            if (p == nullptr)
            {
                pre->next = cur;
                cur->next = nullptr;
            }
        }       
    }

    while(head->next)
    {
        printf("%d\t",head->next->data);
        head = head->next;
    }
}

void PrintNum()
{
    int a[3] = {0};
    PrintfOrderOfProblems(1);

    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&a[i]);
    }

    // sort
    for (int i = 0; i< 2; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int t = a[j + 1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d\t",a[i]);
    }
    putchar('\n');
}

double sum(int n)
{
    if (n == 1)
    {
        return 1.0/ pow(2,1);
    }
    return 1.0 / pow(2,n) + sum(n-1);
}
void GetSum()
{
    PrintfOrderOfProblems(3);
    int a = 0;
    scanf("%d",  &a);
    printf("%f", sum(a));
}

void PrintChar()
{
    PrintfOrderOfProblems(2);
    char c='\0';
    printf("输入大写字母:\t");
    scanf("%c", &c);
    char str[26] = {'\0'};
    int count = 0;

    for(int i = 'A'; i < c; i++)
    {
        count++;
        if(count % 2 == 0)
        {
            str[count - 1] = i + 32;
        }
        else
        {
            str[count - 1] = i;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c", str[i]);
    }
    printf("%c",c);

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

}

void IsHuiWen()
{
    char str[100];
    printf("input a string:");
    scanf("%s",str);

    bool isHuiwen = true;
    
    int i = 0;
    int j = strlen(str) - 1;
    while(i <= j)
    {
        if (str[i] != str[j])
        {
            isHuiwen = false;
            break;
        }
        i++;
        j--;
    }
    printf("%s",isHuiwen ? "YES" : "NO");
}

int main()
{
    GetSum();
    SortNumWithList();
    PrintNum();
    IsHuiWen();
    PrintChar();
    return 0;
}