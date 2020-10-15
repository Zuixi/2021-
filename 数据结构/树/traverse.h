#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <stdio.h>
#include <iostream>

#define Maxsize 100

// 二叉树的链式存储结构
typedef struct TNode
{
    int data;
    struct TNode* lchild;
    struct TNode* rchild;
}TNode;

void visit(TNode* p)
{
    printf("%d\t", p->data);
}

// 二叉树的遍历

// 前序遍历
void preorder(TNode* root);

// 后序遍历
void postorder(TNode* root);

// 中序遍历
void inorder(TNode* root);

// 层次遍历
void level(TNode* root);

// 非递归遍历
void preorderNoRecusion(TNode* root);

void inorderNoRecursion(TNode* root);

void postorderNoRecursion(TNode* root);

// 线索化
void inorderWithThread(TNode* root, TNode* pre);

#endif