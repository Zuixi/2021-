#include "myStack.h"
#include <iostream>

bool IsMatch(char exp[], int n);
void TestStackMatch();

// 后缀表达式求值
int CalCom(char ex[]);
int Op(int a, int b, char op);
void TestOp();

int main()
{
    std::cout << "\n--------------Test stack------------------\n";
    Stack stack;

    std::cout << "\n---------------Init stack------------------\n";
    InitializeStack(stack);

    // push 2
    Push(stack, 2);
    
    // push 3
    Push(stack, 3);

    // pop
    int res;
    Pop(stack, res);
    std::cout << "\n pop element --> " << res << std::endl;

    // pop
    Pop(stack, res);
    std::cout << "\n pop element --> " << res << std::endl;

    if (IsEmpty(stack))
    {
        std::cout << "\nstack is empty\n";
    }

    TestStackMatch();
    TestOp();
    std::cout << "\n----------------Test Over-----------------\n";
    return 0;
}

bool IsMatch(char exp[], int n)
{
    int stack[MaxSize];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(')
        {
            stack[++top] = exp[i];
        }
        else
        {
            // 栈空时遇到）则是不匹配
            if (top == -1)
            {
                return false;
            }
            else
            {
                top--;
            }           
        }        
    }

    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

void TestStackMatch()
{
    char match[] = {'(', '(', ')', ')','(', ')'};
    char notMatch[] =  {'(', '(', ')','(', ')'};

    if (IsMatch(match, 6))
    {
        std::cout << "\nJudge Correctly\n";
    }

    if (!IsMatch(notMatch, 5))
    {
        std::cout << "\nJudge Correctly\n";
    }
}

// 后缀表达式求值
int CalCom(char ex[])
{
    int stack[MaxSize] = {0};
    int top = -1;

    for (int i = 0; ex[i] != '#'; ++i)
    {
        // 如果遇到数组，则入栈
        if (ex[i] <= '9' && ex[i] >= '0')
        {
            stack[++top] = ex[i] - '0';
        }
        else
        {
            char op = ex[i];
            if (top == -1)
            {
                std::cout << "stack is empty\n";
            }

            int b = stack[top--];
            int a = stack[top--];
            int res = Op(a, b, op);
            stack[++top] = res;
        }
        
    }
    return stack[top];
}
int Op(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a * b;
    }
    if (op == '/')
    {
        // 判断除数是否为0
        if (b == 0)
        {
            std::cout << "Error" << std::endl;
            return -1;
        }
        return a / b;
    }
    
    return -1;
}


void TestOp()
{
    char calOne[] = {'1', '2', '3','4', '*', '+', '+', '2', '/', '#'};
    if (CalCom(calOne) == 7)
    {
        std::cout << "Caculate correctly\n";
    }
    else
    {
        std::cout << "res = " << CalCom(calOne) << std::endl;
    }
    
}