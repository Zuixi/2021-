#include "Array.h"
#include <iostream>

void PrintEmptyLine()
{
    std::cout << std::endl;
}

int main()
{
    // 初始化一个Array
    Array arr;
    InitArray(arr);

    if (arr.length == 0)
    {
        std::cout << "Initialize success" << std::endl;
    }

    // 从1-5构造插入array
    for (int i = 1; i < 6; i++)
    {
        InsertAtLast(arr, i);
    }
    
    std::cout << "inset 1 2 3 4 5 to array, now array is as following:\n";
    PrintArray(arr);

    // Insert 2 to ordered array
    InsertOrderArrayWithElement(2, arr);
    std::cout << "\nInsert 2 to ordered array, array is\n";
    PrintArray(arr);

    InsertOrderArrayWithElement(8, arr);
    std::cout << "\nInsert 8 to ordered array, array is\n";
    PrintArray(arr);

    DeleteElementOfIndex(arr, 4);
    std::cout << "\nDelete 4 in array, array is\n";
    PrintArray(arr);

    return 0;
}