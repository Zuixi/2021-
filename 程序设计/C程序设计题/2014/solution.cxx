#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

int main()
{
    return 0;
}