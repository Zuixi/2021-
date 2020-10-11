## 输入10个整数，输出这10数中所有奇数的平均数
**代码实现**
```
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
```
## 输入一个字母，输出以其为核心的字符串。例如，输入E，输出ABCDEDCBA
**代码实现**
```
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
        // 注意这里需要-2，而不是-1，下同
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
```
## 输入两个字符串，将两个字符串合并，删除字符串中的空格，然后将字符串输出
**代码实现**
```
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
```

## 递归计算$1 + \frac{1}{1 * 2} + \frac{1}{2*3} + ... + \frac{1}{n*(n+1)}$, 当第N项小于0.001时停止计算，将计算结果和n的值输出
**代码实现**
```
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

```

## 输入一组数据，将输入数据从大到小存入有序链表中

**代码实现**
```
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

        // 构建第一个数据结点
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
```