## 输入一个字符串，统计其中大写字母、小写字母、数字和空格的数量
```
PrintOrder(1);
    char s[100];
    printf("Enter a string-->: ");
    gets_s(s, 100);

    // a[0] = 大写字母
    // a[1] = 小写字母
    // a[2] = 数字
    // a[3] = 空格数量
    int a[4] = {0};

    for(int i  = strlen(s); i>=0; i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            a[0]++;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            a[1]++;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[2]++;
        }
        if (s[i] == ' ')
        {
            a[3]++;
        }
    }

    printf("count of Uper Alpha char is %d\n",a[0]);
    printf("count of lower Alpha char is %d\n",a[1]);
    printf("count of digit char is %d\n",a[2]);
    printf("count of space char is %d\n",a[3]);
}
```

## 输入一个整数，判断这个整数是否只有0、1、2、4组成。若是的话则将该数输出，否则输出NO
```
void JudgeNum()
{
    PrintOrder(2);
    printf("Enter a num:");
    char num[100];

    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++)
    {
        if(num[i] != '0' || num[i] != '1' || num[i] != '2' || num[i] != '4') 
        {
            printf("NO\n");
            return;
        }
    }
    printf("num is %s", num);
}
```

## 递归求π， 公式为（π * π) / 6 = 1 + 1/(2 * 2) + 1/(3 * 3) + ... + 1/(n * n)。用户输入x,当 1/(n*n)小于x的时候结束递归
```
double RecursionPi(int n, float x)
{
    if (1.0 / (n * n ) < x)
    {
        return 0;
    }
    return 1.0 / (n * n) + RecursionPi(n + 1, x);
}

void GetPi()
{
    double pi = 0;
    // 如果使用double 会出现堆栈溢出
    float x;
    PrintOrder(3);
    printf("Enter a num:");
    scanf("%f",&x);
    pi = 1 + RecursionPi(2, x);
    pi = sqrt(pi * 6);
    printf("pi is %lf", pi);
}
```

## 输入两个字符串，将两个字符串合并，然后将合并后的字符串中的字符按照ASCLL码的顺序输出
```
void MergAndSort()
{
    char* str1;
    char* str2;

    PrintOrder(4);
    printf("Enter two string--> ");
    scanf("%s %s", str1,str2);
    

    strcat(str1, str2);

    printf("merge res is %s", str1);

    // 现在对其排序
    int length = strlen(str1);
    for(int i = 0; i <  length  - 1; i++)
    {
        for (int j = 0; j < length - i -1; j++)
        {
            if (str1[j] > str1[j+1])
            {
                char ch = str1[j+1];
                str1[j+1] = str1[j];
                str1[j] = ch;
            }
        }
    }

    printf("output by ASCLL code is %s", str1);
}
```

## 输入有限个字符串，按照字符串长度从小到大排序，若长度一样，在按照ASCLL码表依次比较字符串中的字符，最后将所有字符串顺序输出
```
typedef struct String
{
    char s[100];
    int len;
}String;

void Outputstring()
{
    String str[20];
    int i,j;
    i = 0;

    // 输入一定的字符串
    do
    {
        gets_s(str[i].s);
        str[i].len = strlen(str[i].s);
        ++i;
    } while (*str[i - 1].s != '\0');

    for (j = 0; j < i - 1; j++)
    {
        // 排序
        for (int k = 1; k < i-1-j; k++)
        {
            if (str[k-1].len > str[k].len)
            {
                String t = str[k-1];
                str[k-1] = str[k];
                str[k] = t;
            }
            else if (str[k-1].len == str[k].len)
            {
                if(strcmp(str[k-1].s, str[k].s) > 0)
                {
                    String t = str[k-1];
                    str[k-1] = str[k];
                    str[k] = t;
                }
            }
        }
    }

    // 输出字符串
    for (int k = 0; k < i-1; k++)
    {
        printf("%s\n", str[k].s);
    }   
}
```