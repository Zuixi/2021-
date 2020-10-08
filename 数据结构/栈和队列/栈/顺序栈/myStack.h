#ifndef STACK_H
#define STACK_H

#include "Global.h"

typedef struct
{
    int data[MaxSize];
    int top;
}Stack;

// 初始化栈
void InitializeStack(Stack& stack)
{
    stack.top = -1;
}

// 判断栈空
bool IsEmpty(const Stack& stack)
{
    if (stack.top == -1)
    {
        return true;
    }

    return false;
}

// 判断栈满
bool IsFull(const Stack& stack)
{
    if (stack.top == MaxSize - 1)
    {
        return true;
    }

    return false;
}

// 入栈
bool Push(Stack& stack, int value)
{
    // 栈满不能入栈
    if(IsFull(stack))
    {
        return false;
    }

    ++stack.top;
    stack.data[stack.top] = value;
    return true;
}

// 出栈
bool Pop(Stack& stack, int& res)
{
    // 栈空不能出栈
    if (IsEmpty(stack))
    {
        return false;
    }

    res = stack.data[stack.top--];
    return true;
}

#endif
