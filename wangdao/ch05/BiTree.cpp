//
// Created by wzq12 on 2022-06-24.
//

#include "BiTree.h"
#include <Stack>

using namespace std;

void visit(BiTree node) {
    if (node) {
        cout << node->data<<' ';
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
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p || !s.empty()) { // 栈不空 或 p不空时循环
        if (p) {
            visit(p);
            s.push(p);
            p = p->lchild;
        } else {
            s.pop();
            p = p->rchild;
        }
    }
}
