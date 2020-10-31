#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    return 0;
}

void SeparateNums()
{
    printf("Enter a num :");
    int n = 0;
    scanf("%d", &n);

    int i = 2;
    while (n > i)
    {
        if (n % i== 0)
        {
            printf("%d ",i);
            n = n / i;
        }
        else
        {
            i++;
        }       
    }
    printf("%d\n", n);
}

void GuessNum()
{
    int sum1 = 0, sum2= 0;
    for (int i = 1; i < 7; i++)
    {        
        for (int j = 0; j < 7; j++)
        {            
            for (int k = 1; k < 7; k++)
            {
                // 若两数相等，则输出结果
                //ijk == kji
                sum1 = i * 49 + j * 7 + k;
                sum2 = i + j * 9 + k * 81;
                if (sum1 == sum2)
                {
                    printf("num is %d\n", sum1);
                }
                else
                {
                    sum1 = sum2 = 0;
                }
           
            }
        }
    }
}

int RecursionGetLen(char str[])
{
    if (*str == '\0')
    {
        return 0;
    }
    return 1 + RecursionGetLen(str + 1);
}

void GetOrderNum()
{
    printf("Enter a number:");
    int n = 0;
    scanf("%d", &n);

    int f1 = 2, f2 = 3;
    
    // 处理特殊case
    if (n == 1)
    {
        printf("num is %d\n", f1);
        return;
    }
    if (n == 2)
    {
        printf("num is %d\n", f2);
        return;
    }

    int count = 2;

    while (count < n)
    {
        int t = f1 * f2;
        if (t / 10 == 0)
        {
            f1 = f2;
            f2 = t;
            ++count;
        }
        else
        {
            f1 = t / 10;
            f2 = t % 10;
            count += 2;
        }       
    }
    printf("num is %d\n", f2);
}

void DeleteDupulicate()
{
    char str[100];
    printf("Enter a string:");
    scanf("%s", str);

    char dst[100] = { '\0' };
    int j = 0;
    for (int i = 0; i < strlen(str);)
    {
        if (j == 0)
        {
            dst[j++] = str[i];
            i++;
        }
        else
        {
            // 在dst中扫描是否出现过这个字符，出现过则i+1，否则入dst中
            bool flag = false;
            for (int k = 0; k < j; k++)
            {
                if (str[i] == dst[k])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                ++i;
            }
            else
            {
                dst[j++] = str[i++];
            }
        }
    }
    printf("res is %s\n", dst);
}