## 输入整数K和N，(1 <= k <=9, 1 <= N <=9),对k和N求和 sum = k + kk + kkk + ... +(n个K);

**例子**
> 输入 k = 2, n = 3
> sum == 2 + 22 + 222

**代码实现**
```
void GetSum()
{
    printf("---------------------NO 1 -------------------\n");
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
```

## 每个数n次方都可以对应N个奇数之和,1^1 = 1,2^2 = 1 + 3，3^3 = 3 + 7 + 17;输入N，输出对应N所对应的的奇数之和

## 输入两字符串，将两个字符串合并，并按照ASCLL码顺序将合并后的字符串输出
```
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
```

## 输入长度为N的由abc构成的排列串
**例子**
> 输入
> 
> n = 2
> 
> 输出
> 
> **aa ab ac ba bb bc ca cb cc**

## 构造一个链表，具体要求如下
> 该链表每个结点包含**两个整数**，将所有结点按照**第一个整数从小到大**排序，如果第一个整数相同，则按照第二个整数从小到大排序

```
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
```