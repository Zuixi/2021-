#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct LNode
{
    int first;
    int second;
    struct LNode* next;
}LNode;

typedef struct TwoData
{
    int first;
    int second;
}TwoData;

LNode* CreateList()
{
     printf("---------------------No 5 -------------------\n");
     TwoData data[10];

     LNode* head = (LNode*)malloc(sizeof(LNode));
     LNode* tail = head;
     tail->next = nullptr;
     LNode* cur;

     // 插入排序

     for(int i = 0; i < 10; i++)
     {
         scanf("%d %d", &data[i].first, &data[i].second);
     }

     for (int i = 0; i < 10; i++)
     {
         LNode* s = (LNode*)malloc(sizeof(LNode));
         s->first = data[i].first;
         s->second = data[i].second;

         if (head->next == nullptr)
         {
             tail->next = s;
             s->next = nullptr;
         }
         else
         {
            LNode *p,*pre;
            pre = head;
            p = head->next;
            while(p->next != nullptr)
            {
                if ( p->first > s->first)
                {
                    pre->next = s;
                    s->next = p;
                    break;
                }
                else if (p ->first == s->first && p->second > s->second)
                {
                    pre->next = s;
                    s->next = p;
                    break;
                }
                else
                {
                    pre = pre->next;
                    p = p->next;
                }               
            }
         }
         
     }

    return head;
}

int main()
{
    return 0;
}

void GetSum()
{
    printf("---------------------No 1 -------------------\n");
    printf("Input two numbers k and n:");
    int k, n;
    int sum = 0;
    scanf("%d %d",&k ,&n);

    for (int i = 0; i < n; i++)
    {
        sum += sum * 10 + k;
    }
    printf("sum = %d\n", sum);
}

void PrintString()
{
    char str[100];
    char str1[100];
    char res[1000] = {'\0'};

    printf("---------------No 3------------------------\n");
    printf("Enter two strings:");
    scanf("%s %s", str, str1);

    strcat(res, str);
    strcat(res, str1);

    // sort
    for(int i = 0; i < strlen(res); i++)
    {
        for (int j = 0; j < strlen(res) - 1 - i; j++)
        {
            if (res[j] > res[j + 1])
            {
                char t = res[j];
                res[j] = res[j + 1];
                res[j + 1] = t;
            }
        }
    }

    printf("res is %s\n", res);
}

void PrintNum()
{
    // 数的N次方对应N个奇数之和
    
}

void RecursionPrintfString(int n, char str[])
{
    if (n == 0)
    {
        printf("str is %s\n", str);
        return;
    }
    // 递归全排列

    RecursionPrintfString(n - 1, strcat(str,"a"));
    RecursionPrintfString(n - 1, strcat(str,"b"));
    RecursionPrintfString(n - 1, strcat(str,"c"));

}