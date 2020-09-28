#include "List.h"

// 用于测试链表中的算法是否有误
int main()
{
    LNode* headCreation;
    LNode* tailCreation;

    int array[5] = {1, 2, 3, 4, 5};
    std::cout << "---------------List Test Begin------------------\n";

    std::cout << "\n---------------Insert element at tail-------------\n";
    CreateListAtTail(tailCreation, array, 5);
    PrintList(tailCreation);

    std::cout << "\n---------------Insert element at head-------------\n";
    CreateListAtHead(headCreation, array, 5);
    PrintList(headCreation);

    std::cout << "\n----------------Delete element at list-------------\n";
    DeleteElement(tailCreation, 3);
    PrintList(tailCreation);

    std::cout << "\n----------------Reverse List---------------------\n";
    ReverseList(tailCreation);
    PrintList(tailCreation);

    std::cout << "\n----------------Insert element in ordered List------------\n";
    LNode* orderedList;
    CreateListAtTail(orderedList, array, 5);
    std::cout << "before Insert, List as follows:\n";
    PrintList(orderedList);
    std::cout << "After Insert, List as follows:\n";
    InsertInOrderedList(orderedList, 3);
    PrintList(orderedList);

    std::cout << "\n----------------Merge two ordered List to one List--------------\n";
    LNode* temp;
    int tempArr[3] = {0,8,10};
    CreateListAtTail(temp, tempArr, 3);
    PrintList(MergeOrderedList(orderedList, temp));

    std::cout << "\n---------------List Test Over------------------\n";
    return 0;
}