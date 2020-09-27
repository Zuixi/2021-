#ifndef LIST_H
#define LISH_H

#include <iostream>
#include <string>

// 单链表
typedef struct LNode
{
    int data;    // 数据
    struct LNode* next;
}LNode;

// 双链表
typedef struct DNode
{
    int data;
    struct DNode* next;      // 后置结点指针
    struct DNode* prior;     // 前置结点指针
}DNode;

#endif