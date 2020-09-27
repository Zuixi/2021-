#include "Array.h"
#include <iostream>
// 对于顺序表

// 初始化列表
void InitArray(Array& arr)
{
    arr.length = 0;
}

// 按照元素值的查找办法
int FindFirstElement(const Array& arr, int value)
{
    if (arr.length == 0)
    {
        std::cout << "Array is Empty" << std::endl;
        return -1;
    }

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.data[i] == value)
        {
            return i;
        }
    }

    // 如果不存在，则返回-1
    return -1;
}

// 在末尾插入元素
bool InsertAtLast(Array& arr, int value)
{
    if (arr.length >= MaxSize)
    {
        std::cout << "Array is full" << std::endl;
        return false;
    }
    else
    {
        arr.data[arr.length] = value;
        arr.length++;
    }
    return true;   
}

// 删除指定位置元素
bool DeleteElementOfIndex(Array& arr ,int index)
{
    if (arr.length == 0)
    {
        return false;
    }

    for (int i = index; i < arr.length - 1; i++)
    {
        arr.data[i] = arr.data[i + 1];
    }

    arr.length -= 1;
    return true;
}  

// 在一个顺序表L中，其中的元素递增有序排列
// 插入元素X，使得插入后的元素依然有序排列
bool InsertOrderArrayWithElement(int value, Array& arr)
{
    // 元素递增有序排列，所以需要找到第一个比X大的位置
    int firstIndex = 0;

    for(int i = 0; i < arr.length; i++)
    {
        if (arr.data[i] > value)
        {
            firstIndex = i;
            break;
        }
    }

    // 如果没有比X大的元素，那么就是插入最后一个元素
    if (firstIndex == 0)
    {
        firstIndex = arr.length;
    }
    
    if (arr.length + 1 > MaxSize)
    {
        std::cout << "Array is full" << std::endl;
        return false;
    }

    // 找到第一个比X大的元素后，需要将后面的元素依次后移一个单位
    // | 0 | 1 | 2 | 3 | 4|
    for (int i = arr.length - 1; i >= firstIndex; i--)
    {
        arr.data[i + 1] = arr.data[i];
    }
    arr.data[firstIndex] = value;
    arr.length++;
    return true;
}

// 在指定位置插入元素
// | 0 | 1 | 2 | 3 | 4 | ''' | p | ''' | n |
// 在 P 处插入新的元素
bool InsertElementAtIndex(Array& arr, int index, int value)
{
    if (index < 0  || index > MaxSize || arr.length == MaxSize)
    {
        std::cout << "Index not legal or Array is full" << std::endl;
        return false;
    }

    for (int i = arr.length - 1; i >= index; --i)
    {
        arr.data[i + 1] = arr.data[i];
    }
    arr.data[index] = value;
    arr.length++;
    
    return true;
}

// 返回指定位置的元素，用res 表示结果
int GetValueOfIndex(const Array& arr, int index, int& res)
{
    if (index < 0 || index > arr.length)
    {
        std::cout << "index not legal" << std::endl;
        return -1;
    }
    res = arr.data[index];
    
    // 0 is success
    return 0;
}

// 输出Array的所有元素
void PrintArray(const Array& arr)
{
    if (arr.length < 0)
    {
        std::cout << "No element to print" << std::endl;
    }

    for (int i = 0; i < arr.length; i++)
    {
        std::cout << arr.data[i] << "\t";
    }
    std::cout << std::endl;
}
  