#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    Node* next;
    int data;
}Node;

void CalAvergeNum()
{
    printf("---------------No1-------------------\n");
    int a;
    int count = 0;
    int s = 0;
    while(scanf("%d", &a) != EOF)
    {
        if (a % 2 != 0)
        {
            s += a;
            count++;
        }
    }

    printf("res of average num is %d\t, count = %d\n", s / count, count);
    printf("---------------No1 End-------------------\n");
}

void OutPutCoreString()
{
    char a;
    printf("---------------No2-------------------\n");
    printf("enter a charcter-->\t");
    scanf("%c", &a);

    if ('a' <= a && 'z' >= a)
    {
        char flag = 'a';
        while (flag <= a)
        {
            putchar(flag);
            ++flag;
        }
        flag -= 2;
        while (flag >= 'a')
        {
            putchar(flag);
            --flag;
        }       
    }
    
    if ('A' <= a && 'Z' >= a)
    {
        char flag = 'A';
        while (flag <= a)
        {
            putchar(flag);
            ++flag;
        }
        flag -= 2;
        while (flag >= 'A')
        {
            putchar(flag);
            --flag;
        }       
    }

    printf("\n---------------No2 End-------------------\n");
}

void MergeString()
{
    printf("------------No3-----------------------\n");
    char s[] = "abc  dd";
    char t[] = "ff  gf j";
    char res[100];
    //res should abcddffgfj
  
    int len = 0;
    int length = 0;
    while (len < sizeof(s))
    {
        if (s[len] != ' ')
        {
            res[length++] = s[len];
        }
        len++;
    }
    // 去掉最后自加的长度
    length--;

    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] != ' ')
        {
            res[length++] = t[i];
        }
    }

    printf("%s\n", res);
    printf("\n--------------------No3 End------------------\n");
}

void InsertData()
{
    printf("\n----------------------No5--------------------\n");
    int a;
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = nullptr;
    Node* tail = head;

    while (scanf_s("%d", &a) && a != -1)
    {
        // malloc 引入stdlib.h
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->data = a;

        // 构建第一个头结点
        if (tail->next == nullptr)
        {
            tail->next = cur;
            cur->next = nullptr;
        }
        else
        {
            // 从大到小构造链表
            Node* pre = head;
            Node* p = head->next;

            while (p != nullptr)
            {
                // p < cur 插入在p前面
                if (p->data <= cur->data)
                {
                    cur->next = p;
                    pre->next = cur;
                    break;
                }
                // 依次遍历链表
                p = p->next;
                pre = pre->next;
            }

            if (p == nullptr)
            {
                // 如果输入的数据比最后一个都小的话，插入在最后
                pre->next = cur;
                cur->next = nullptr;
            }
          
        }
    }

    while (head->next != nullptr)
    {
        printf("%d\t", head->next->data);
        head = head->next;
    }

    printf("\n----------------------No5 End--------------------\n");
}

double RecursionCal(int n)
{
    if (1.0 / ((n + 1) * n) < 0.001)
    {
        printf("n ==  %d\n", n);
        return 0;
    }
    if (n == 1)
    {
        return 1 + RecursionCal(1 + n);
    }
    return 1.0 / ((n + 1) * n) + RecursionCal(n + 1);
}

int main()
{
    InsertData();
    MergeString();
    OutPutCoreString();
    int a;
    printf("Enter your select for solution of problems\t");
    while(scanf("%d", &a) != EOF)
    {
        switch (a)
        {
        case 1:
            CalAvergeNum();
            break;
        case 2:
            OutPutCoreString();
            break;
        case 3:
        default:
            break;
        }
    }
    printf("-----------------Exit----------------------");
    return 0;
}