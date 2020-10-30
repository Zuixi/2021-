## 从键盘键入三个数abc，判断是否可以构成三角形，如果能则输出YES，否则输出NO
```
void JudgeTriangle()
{
    printf("--------------------No 1 Triangle----------------------\n");
    int a,b,c;

    printf("Please input three numbers:");
    scanf("%d %d %d",&a, &b, &c);

    // 做判断
    // 两边之和大于第三边且两边之差小于第三边
    bool flag = false;
    if (a + b > c && a + c > b && b + c > a )
    {
        if (abs(a - b) < c && abs(a - c) < b && abs(b - c) > a)
        {
            flag = true;
        }
    }
    printf("%s\n", flag ? "YES" : "NO");
}
```
## 从键盘键入两个字符串str1,str2，合并这两个字符串到str3中，具体规则如下：
>**str1的第一个字符+str2的第一个字符**，**str1的第二个字符拼接str2的第二个字符**;若有一个字符合并完毕，则将剩余的字符串直接开加到str3之后

```
void MergeString()
{
    printf("\n--------------------No 2 String Merge----------------------\n");
    char str1[100];
    char str2[100];
    char str3[300];
    int i = 0,j = 0;
    int count = 0;

    printf("Please input two string:\n");
    scanf("%s %s", str1, str2);

    printf("str1 is %s\n", str1);
    printf("str1 is %s\n", str1);

    while(str1[i] != '\0' && str2[j] != '\0')
    {
        str3[count++] = str1[i++];
        str3[count++] = str2[j++];
    }

    if (str1[i] == '\0')
    {
        while(str2[j] != '\0')
        {
            str3[count++] = str2[j++];
        }
    }

    if (str2[j] == '\0')
    {
        while(str1[i] != '\0')
        {
            str3[count++] = str1[i++];
        }
    }

    str3[count] = '\0';

    printf("Merge res is %s\n",str3);
    
}
```

## 存在某一数列：2/1, 3/2, 5/3, 8/5, 13/8...要求从键盘键入数字n，输出该数列的前N项和

```
void GetSum()
{
    printf("Please input a number:");
    float sum = 0;
    int a = 2;
    int b = 1;
    int n;
    scanf("%d", &n);
    int count = 0;
    
    while(1)
    {
        if (count == n)
        {
            break;
        }
        
        sum += a * 1.0 / b;
        int t = a + b;
        b = a;
        a = t;
        ++count;
    }
    printf("sum is %f", sum);
}
```

## 从键盘键入一个长字符串，一个匹配字符串，一个替换字符串。首先在长字符串中查找匹配字符串，如果有匹配字符串，则用替代字符串替换
```
void SubStr()
{
    printf("----------------------No 4 Substr--------------------\n");
    char str[100];
    char substr[20];
    char replacestr[100];
    char res[1000];

    printf("Enter three strings");
    scanf("%s %s %s", str, substr, replacestr);
    int index = GetIndex(str, substr);
    // search substr
    if ( index != -1)
    {   int j = 0;
        for (int i = 0; i < index; i++)
        {
            res[j++] = str[i];
        }

        for (int i = 0; i < strlen(replacestr); i++)
        {
            res[j++] = str[i];
        }

        for (int i = index; i < strlen(str); i++)
        {
            res[j++] = str[i];
        }
        res[j] = '\0';
    }
    printf("res is %s\n", res);
}

int GetIndex(char str[], char substr[])
{
    int index = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        int k = i; 
        int j = 0;
        for (; j < strlen(substr); j++)
        {
            if (substr[j] == str[k] && k < strlen(str))
            {
                k++;
            }
            else
            {
                break;
            }
        }

        if (j >= strlen(substr))
        {
            index = i;
            break;
        }
    }
    return index;
}
```

## 从键盘键入10个数字，先求这10个数的平均数，然后将小于平均值的数先输出，然后输出大于平均值的数

```
void OutputNumber()
{
    printf("\n------------------No5 Printf Number-----------------\n");
    printf("enter 10 numbers:");

    int a[10] = {0};
    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }

    float aver = 0;
    for (int i = 0; i < 10; i++)
    {
        aver += a[i];
    }
    aver /= 10;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] < aver)
        {
            printf("%d\t", a[i]);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (a[i] > aver)
        {
            printf("%d\t",a[i]);
        }
    }
    printf("\n");
}
```