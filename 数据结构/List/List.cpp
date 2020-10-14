
#include "List.h"

// 带头结点的尾插法
// [head | next] --> [data1 | next] --> [data2 | next] --> ... --> [datan | next] --> NULL
void CreateListAtTail(LNode* &head, int array[], int length)
{
    LNode* tail;
    LNode* cur;    // cur用于存放数据， tail始终指向最后一个节点

    // int sizeOfArray = sizeof(array) / sizeof(int);
    // 这里获取sizeofArray时在我的编译器里出现问题，下面语句用于测试
    // std:: cout <<"\nsizeof(array) = " << sizeof(array) << "\tsizeof(int) = " << sizeof(int) << std::endl;

    head = (LNode*) malloc(sizeof(LNode));
    head->next = nullptr;
    tail = head;

    for (int i = 0; i < length; i++)
    {
        cur = (LNode*)malloc(sizeof(LNode));
        cur->data = array[i];
        // 链接下一个节点
        tail->next = cur;
        // 指向末尾节点
        tail = cur;
    }

    tail->next = nullptr;
}

// 带头结点的头插法
// [head | next] --> [datan | next] --> [data(n - 1) | next] --> ... --> [data1 | next] --> NULL
// cur->next = head->next; cur->data = array[i]; 
void CreateListAtHead(LNode* &head, int array[], int length)
{
    LNode* cur;

    head = (LNode*)malloc(sizeof(LNode));
    head->next = nullptr;

    // int sizeOfArray = sizeof(array) / sizeof(int);  这个在vscode中会出现问题  sizeof(array) = 4       sizeof(int) = 4
    for (int i = 0; i < length; i++)
    {
        cur = (LNode*)malloc(sizeof(LNode));
        cur->data = array[i];
        
        cur->next = head->next;    // 当前结点指向开始结点
        head->next = cur;          // 开始结点指向当前结点，使得当前结点成为开始结点
    }
    
}

// 打印链表
void PrintList(LNode* head)
{
    LNode* cur = head->next;
    while(cur != nullptr)
    {
        std::cout << cur->data << "\t";
        cur = cur->next;
    }

    std::cout << "\nPrint element in List Processed\n";
}

// 删除指定元素X
bool DeleteElement(LNode* &head, int value)
{
    // 用一前一后两个扫描指针探索元素
    LNode* pre;
    LNode* cur;
   
    cur = head;
    pre = head->next;

    while(pre != nullptr)
    {
        if (pre->data == value)
        {
            cur->next = pre->next;           
            LNode* del = pre;
            // pre 需要指向被删除的下一个结点
            pre = pre->next;
            delete(del);
        }
        else
        {
            pre = pre->next;
            cur = cur->next;
        }             
    }

    return true;
}

// 颠倒链表
// [head | next] --> [A1 | next] --> [A2 | next] --> null
// changed to as follows
// [head | next] --> [A2 | next] --> [A1| next] --> null
void ReverseList(LNode* &head)
{
    LNode* cur;

    // 一个一个结点摘下来，使用头插法构造节点
    cur = head->next;
    head->next = nullptr;

    while(cur != nullptr)
    {
        LNode* tempcur = cur;
        cur = cur->next;

        // 使用头插法构造链表
        tempcur->next = head->next;
        head->next = tempcur;
    }
}

// 在有序表中插入一个元素X让其仍然有序
// [head | next] --> [1 | next] --> [3 | next] --> [5 | next] --> [6 | next] --> nullptr
// insert 3 in this list
// [head | next] --> [1 | next] --> [3 | next] --> [3 | next] --> [5 | next] --> [6 | next] --> nullptr
void InsertInOrderedList(LNode* &head, int value)
{
    LNode* cur;
    LNode* pre;

    cur = head;
    pre = head->next;

    while(pre != nullptr)
    {
        // 找到第一个比value大的元素
        if (pre->data > value)
        {
            LNode* temp;
            temp = (LNode*)malloc(sizeof(LNode));
            temp->data = value;

            temp->next = pre;
            cur->next = temp;
            break;
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }
}

// 合并两个有序的链表成为一个有序链表
// [headA | next] --> [1 | next] --> [3 | next] --> [5 | next] --> [6 | next] --> nullptr
// [headB | next] --> [1 | next] --> [3 | next] --> [5 | next] --> [6 | next] --> nullptr
// merge two List to one orderedList
// [head | next] --> [1 | next] --> [1 | next] --> [3  | next] --> [3 | next] --> [5 | next] --> [6 | next] --> nullptr
LNode* MergeOrderedList(LNode* headA, LNode*headB)
{
    LNode* headC;
    headC = (LNode*)malloc(sizeof(LNode));
    headC->next = nullptr;
    LNode* tail;    // 始终指向尾结点
    tail = headC;

    // 用两个节点遍历两个链表
    LNode* itrOfA;
    LNode* itrOfB;

    itrOfA = headA->next;
    itrOfB = headB->next;

    while(itrOfB != nullptr && itrOfA != nullptr)
    {
        if (itrOfB->data <= itrOfA->data)
        {
            tail->next = itrOfB;
            tail = tail->next;
            itrOfB = itrOfB->next;
        }
        else
        {
            tail->next = itrOfA;
            tail = tail->next;
            itrOfA = itrOfA->next;
        }
        
    }

    // 处理剩余的链表元素
    if (itrOfB != nullptr)
    {
        tail->next = itrOfB;
    }

    if (itrOfA != nullptr)
    {
        tail->next = itrOfA;
    }

    return headC;
}

// 双链表的尾插法
void CreateDListTail(DNode* head, int arr[], int length)
{
    head = (DNode*)malloc(sizeof(DNode));
    head->next = head-> prior = nullptr;

    DNode* tail;    // 始终指向尾部元素
    tail = head;

    for (int i = 0; i < length; i++)
    {
        DNode* temp = (DNode*)malloc(sizeof(DNode));
        temp->data = arr[i];

        tail->next = temp;
        temp->prior = tail;
        tail = tail->next;
    }
    tail->next = nullptr;
}

// 实现集合的运算 C = A - B
void SubstractSet(LNode* headA, LNode* headB)
{
    LNode* pB = headB;
    LNode* pA;

    while(pB->next)
    {
        // 从B中拿出一个结点依次和A中的结点做比较，相同则从A中删除
        pA = headA;
        while(pA->next)
        {
            if (pA->next->data == pB->next->data)
            {
                // 相同从A 中删除该结点
                LNode* temp;
                temp = pA->next;
                pA->next = pA->next->next;
                free(temp);
                pA = pA->next;
            }
        }
        pB = pB->next;
    }
}