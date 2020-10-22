## 选择排序
> 从头到尾扫描序列，找出最小一个关键字，和第一个关键字交换，接着剩下的关键字重复此步骤，最后序列会变得有序

**示例代码**
```
void SelectSort(int arr[], int n)
{
    int k;

    for (int i = 0; i < n; i++)
    {
        k = i;
        //从i后面的序列中选择最小的和i交换
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }

        // 执行交换
        if (i != k)
        {
            t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
        }
    }
}
```

## 堆排序
