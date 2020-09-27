#ifndef ARRAY_H
#define ARRAY_H

#include "Global.h"

// 顺序表
typedef struct Array
{
    int data[MaxSize];
    int length;
}Array;

// 顺序表中最重要的操作就是插入，删除，查找

void InitArray(Array& arr);

// 按照元素值的查找办法
int FindFirstElement(const Array& arr, int value);

// 在末尾插入元素
bool InsertAtLast(Array& arr, int value);

// 删除指定位置元素
bool DeleteElementOfIndex(Array& arr ,int index);

// 在一个顺序表L中，其中的元素递增有序排列
// 插入元素X，使得插入后的元素依然有序排列
bool InsertOrderArrayWithElement(int value, Array& arr);

// 在指定位置插入元素
// | 0 | 1 | 2 | 3 | 4 | ''' | p | ''' | n |
// 在 P 处插入新的元素
bool InsertElementAtIndex(Array& arr, int index, int value);

// 返回指定位置的元素，用res 表示结果
int GetValueOfIndex(const Array& arr, int index, int& res);

// 输出Array的所有元素
void PrintArray(const Array& arr);

#endif