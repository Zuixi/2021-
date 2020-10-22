## 冒泡排序
> 通过一系列**交换动作**完成排序。

**具体过程**
> 首先第一个关键字比第二个关键字大的话，则交换二者，不然不交换，然后第二个和第三个比较，如果第二个大，则二者交换，否则不交换，重复这个过程，最大的那个数字被交换到了最后的位置，一趟冒泡排序完成。经过多次这样的排序，整个序列都将变得有序


**排序示例**

原始序列：**49 38 65 97 76 13 27 49**

**第一趟冒泡排序过程如下**
1. 49比38 大，交换二者位置
> **38 49 65 97 76 13 27 49**

2. 49比65小，不交换

3. 65比97小，不交换
4. 97比76大，交换二者
> **38 49 65 76 97 13 27 49**

5. 97比13大，交换二者
> **38 49 65 76 13 97 27 49**

6. 97比27大，交换二者
> **38 49 65 76 13 27 97 49**

7. 97比49大，交换二者
> **38 49 65 76 13 27 49 97**

进过一趟排序，最大的数97到了自己最终的位置

**代码示例**
```
// 从小到大排列
void BubbleSort(int Array[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                t = Array[j+1];
                Array[j+1] = Array[j];
                Array[j] = t;
            }
        }
    }
}


// 从大到小排列
void BubbleSort2(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n -1; i++)
    {
        bool flag = false;
        for (j = n - 1; j >= i + 1; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }

        if (flag == false)
        {   
            // 已经有序
            return;
        }
    }
}
```

## 快速排序
**手工执行快速排序的过程**

**算法代码**
```
void QuickSort(int arr[], int low, int high)
{
    int i,j,t;

    i = low;
    j = high;

    if (low < high)
    {
        t = arr[low];

        // 开始一趟排序
        while(i < j>)
        {
            //  从右边开始扫描
            while(j> i && arr[j] >= t )
                j--;
        
            // 将arr[j] 放到arr[i],i 开始扫描
            if (i < j)
            {
                arr[i] = arr[j];
                i++;
            }
            

            while(i < j && arr[i] < t)
            {
                i++;
            }
            if (i < j)
            {
                 arr[j] = arr[i];
                 j--;
            }
           
        }

        // 结束比较
        arr[i] = t;
        QuickSort(arr, low, i-1);   // 左序列
        QuickSort(arr, i+1, high);  // 右序列
        
    }
}
```