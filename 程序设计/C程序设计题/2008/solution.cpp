#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
    return 0;
}



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

float RecursionGetSum(int n)
{
    if (n == 1)
    {
        return 1.0;
    }
    int flag = n % 2 == 0  ? -1 : 1;
    return flag * 1.0 / n + RecursionGetSum(n - 1);
}

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
