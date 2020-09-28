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

// 对于单链表而言

// 带头结点的尾插法
void CreateListAtTail(LNode* &head, int array[], int length);

// 带头结点的头插法
void CreateListAtHead(LNode* &head, int array[], int length);

// 打印链表
void PrintList(LNode* head);

// 删除指定元素X
bool DeleteElement(LNode* &head, int value);

// 颠倒链表
void ReverseList(LNode* &head);

// 在有序表中插入一个元素X让其仍然有序
void InsertInOrderedList(LNode* &head, int value);

// 合并两个有序的链表成为一个有序链表
LNode* MergeOrderedList(LNode* headA, LNode*headB);

#endif