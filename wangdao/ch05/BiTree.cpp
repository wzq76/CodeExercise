//
// Created by wzq12 on 2022-06-24.
//

#include "BiTree.h"
#include <stack>
#include <iostream>
#include "../templates/SqQueueTemplate.hpp"
#include "../templates/SqStackTemplate.hpp"

using namespace std;

void visit(BiTree node) {
    if (node) {
        cout << node->data << ' ';
    } else {
        cout << "NULL";
    }
}

void Create(BiTree &root, char const *&elements) {
    ElemType c = *elements;
    if (c == '\0') {
        return;
    }
    if ('#' == c) {
        root = NULL;
        elements++;
    } else {
        root = (BiTNode *) malloc(sizeof(BiTNode));
        root->data = c;

        elements++;
        Create(root->lchild, elements);
        Create(root->rchild, elements);
    }
}

void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void PreOrder2(BiTree T) {
//    stack<BiTNode *> s;

    SqStack<BiTNode *> s;
    InitStack(s);

    BiTNode *p = T;
    while (p || !StackEmpty(s) /*!s.empty()*/ ) { // 栈不空 或 p不空时循环
        if (p) {
            visit(p);
//            s.push(p);
            Push(s, p);
            p = p->lchild;
        } else {
//            s.pop();
            Pop(s, p);
            p = p->rchild;
        }
    }
}

void PreOrder22(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p || !s.empty()) { // 栈不空 或 p不空时循环
        if (p) {
            visit(p);
            s.push(p);

            p = p->lchild;
        } else {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void InOrder22(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p || !s.empty()) { // 栈不空 或 p不空时循环
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            visit(p);
            s.pop();
            p = p->rchild;
        }
    }
}

void PostOrder22(BiTNode *T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    BiTNode *r = NULL;

    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;  //找最左面
        } else {
            p = s.top();    //左子树为空，找栈顶元素
            if(p->rchild && p->rchild!=r){  //栈顶元素右子树存在且未被访问过就入栈
                p = p->rchild;
                s.push(p);
                p = p->lchild;//找最左面
            }else{
                visit(p);
                s.pop();
                r = p;// 区分返回是从左子树返回的还是从右子树返回的, 因此设定一个辅助指针 r
                p=NULL;
            }


        }


    }
}