#include "traverse.h"

// 二叉树的遍历

// 前序遍历
void preorder(TNode* root)
{
    if (root != nullptr)
    {
        // 访问根节点
        visit(root);
        // 左儿子
        preorder(root->lchild);
        // 右儿子
        preorder(root->rchild);
    }
}

// 后序遍历
void postorder(TNode* root)
{
    if(root != NULL)
    {
        // 左儿子
        postorder(root->lchild);

        // 右儿子
        postorder(root->rchild);

        // 根节点 
        visit(root);
    }
}

// 中序遍历
void inorder(TNode* root)
{
    if (root != nullptr)
    {
        // 左儿子
        inorder(root->lchild);

        // 访问根节点
        visit(root);

        // 右儿子
        inorder(root->rchild);
    }
}

// 层次遍历
// 需要使用一个辅助队列,先进先出
void level(TNode* root)
{
    if(root != nullptr)
    {
        // 定义一个循环队列
        TNode* queue[Maxsize];
        int front,rear;
        front = rear = 0;

        // 根节点入队
        rear = (rear + 1) % Maxsize;
        queue[rear] = root;

        // 当队列不为空的时候
        while(front != rear)
        {
            // 出队
            front = (front + 1) % Maxsize;
            TNode* cur;
            cur = queue[front];
            visit(cur);

            if (cur->lchild != nullptr)
            {
                // 左儿子入队
                rear = (rear + 1) % Maxsize;
                queue[rear] = cur->lchild;
            }
            if (cur->rchild != nullptr)
            {
                // 右儿子入队
                rear = (rear + 1) % Maxsize;
                queue[rear] = cur->rchild;
            }
        }
    }
}

// 非递归遍历
// 使用一个辅助栈，根节点入栈
// 出栈后，如果有右儿子，右儿子入栈，如果有左儿子，左儿子入栈
// 出栈，重复2，当且仅当栈为空的时候结束
void preorderNoRecusion(TNode* root)
{
    TNode* stack[Maxsize];
    int top = -1;

    // 根节点入栈
    stack[++top] = root;

    while(top != -1)
    {
        // 出栈
        TNode* cur;
        cur = stack[top--];
        visit(cur);

        if (cur->rchild != nullptr)
        {
            stack[++top] = cur->rchild;
        }

        if (cur->lchild != nullptr)
        {
            stack[++top] = cur->lchild;
        }
    }

}

//                A
//            B       F
//         C     D
// 这个二叉树的中序遍历是C B D A F
// 非递归思想
// 根节点入栈
// 如果根节点左儿子也存在，左儿子入栈，如果栈顶左儿子不存在，则出栈并访问该结点
// 访问结点之后，如果右儿子存在，右儿子入栈
// 栈空时算法结束
void inorderNoRecursion(TNode* root)
{
    TNode* stack[Maxsize];
    int top = -1;
    TNode* bt = root;

    // 栈不空的时候
    while(top != -1 || bt != nullptr)
    {
        TNode* cur;
        
        // 左儿子入栈
        while(bt != nullptr)
        {
            stack[++top] = bt;
            bt = bt->lchild;
        }

        // 出栈
        if (top != -1)
        {
            bt = stack[top--];
            visit(bt);
            bt = bt->rchild;
        }
    }
}

void postorderNoRecursion(TNode* root)
{

}

// 线索化
void inorderWithThread(TNode* root, TNode* pre)
{
    
}