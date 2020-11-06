## 递归实现将输入的字符串反序输出

```
void RecursionPrintString(char s[], int n)
{
    if (n >= strlen(s))
    {
        return;
    }

    RecursionPrintString(s, n + 1);
    printf("%c", s[n]);
}
```
## 将一个数的数字倒过来得到的新数叫原数的反序数，若两数字相等，则称为对称数，求不超过2006的最大对称数。
```
void GetSymethyNumber()
{
    int n = 1;
    int i = 1;
    int t = 0;
    while (1)
    {
        // 求反序数
        if (i > 2006)
        {
            break;
        }
        int sum = 0;
        int res = i;
        while (res != 0)
        {
            sum = sum * 10 + res % 10;
            res = res / 10;
        }
        if (sum == i)
        {
            t = i;
        }
        i++;
    }
    printf("num is %d", t);
}
```