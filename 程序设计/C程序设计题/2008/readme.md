## 从键盘键入自然数段的两个端点值，例如200-500，分别计算这些自然数中的奇数之和与偶数之和
**代码实现**
```
void GetSum()
{
    printf("-----------------------No 1-----------------------\n");
    int a,b;
    int i = 0;
    scanf("%d %d", &a, &b);

    int sum1 = 0, sum2 = 0;
    for (i = a; i <= b; i++)
    {
        if (i %2 == 0)
        {
            sum1 += i;
        }
        else
        {
            sum2 += i;
        }
    }

    printf("奇数之和 = , 偶数之和 = \n", sum2, sum1);
}
```

## 编写一个函数before(int old[], int new[]), 把整数数组old所有的偶数放到所有的奇数前面，并将新的序列存放到new中
**代码实现**
```
void Before(int old[], int newArr[])
{
    int len = sizeof(old) / sizeof(int);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (old[i] % 2 == 0)
        {
            newArr[j++] = old[i];
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (old[i] % 2 != 0)
        {
            newArr[j++] = old[i];
        }
    }
}
```

## 递归计算1 + 1/2 - 1/3 + 1/ 4 -1/5
**代码实现**
```
float RecursionGetSum(int n)
{
    if (n == 1)
    {
        return 1.0;
    }
    int flag = n % 2 == 0  ? -1 : 1;
    return flag * 1.0 / n + RecursionGetSum(n - 1);
}
```

## 输入一个字符串，以空格作为单词分隔符，将整个字符串按照单词反序输出

**示例**
> 输入

> "An apple!"

> 输出

> apple! an

**代码实现**
```
void RevertString()
{
    char arr[100];
    scanf("%s", arr);

    for (int j = strlen(arr) - 1; j >= 0; )
    {
        int i = j;
        // i 向前扫描，扫到空格为止
        while (arr[i] != ' ' && i >= 0)
        {
            i--;
        }

        // a[i]- a[j] 单词+ symbol
        char t[20] = { '\0' };
        int count = 0;
        for (int k = i + 1; k < j; k++)
        {
            t[count++] = arr[k];
        }
        t[count] = '\0';

        printf("%s%c ", t, arr[j]);
        j = i - 1;
    }
}
```

## S是一个函数数字字符和非数字字符的字符串(长度不超过80)，将其中连续的数字字符转为一个数组，若数字个数超过5个，则5个一组转换。将转换后的数字存到数组Arr中。
**例子**
> 输入

> "a123b45!786j97df123456789hg"

> 数组Arr中元素有

> 123 45 786 97 12345 6789

**代码实现**
```
void GetNumFromString()
{
    char str[100];
    int Arr[20];
    int length = 0;
    scanf("%s", str);

    int i = 0, j = 0;

    for (int i = 0; i < strlen(str);)
    {
        // j 开始扫描最长的数字字符
        int count = 0;
        for (j = i; j < strlen(str);)
        {
            if ('0' <= str[j] && str[j] <= '9')
            {
                j++;
                count++;
                if (count % 5 == 0)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        // j != i 说明含有含有数字字符
        if (j != i)
        {
            char num[6] = { '\0' };
            int len = 0;
            for (int k = i; k < j; k++)
            {
                num[len++] = str[k];
            }

            // 将获取到的数字字符转化为数字
            int sum = 0;
            for (int k = 0; num[k] != '\0'; k++)
            {
                sum = sum * 10 + num[k] - '0';
            }
            if (sum != 0)
            {
                Arr[length++] = sum;
            }
            i = j;
        }
        else
        {
            i++;
        }
    }

    for (int k = 0; k < length; k++)
    {
        printf("%d ", Arr[k]);
    }
}
```
