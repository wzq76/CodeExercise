//
// Created by wzq12 on 2022-06-23.
//

#ifndef CODEEXERCISE_BITREE_H
#define CODEEXERCISE_BITREE_H

#include <iostream>
#include <cstdlib>
typedef char ElemType;
using namespace std;
typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild,*rchild;
    BiTNode(int x) : data(x), lchild(NULL), rchild(NULL) {}
}BiTNode,*BiTree;

void Create(BiTNode &root,char const *&elements);
void visit(BiTree T);

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

void PreOrder2(BiTree T);
void InOrder2(BiTree T);
void PostOrder2(BiTree T);

void LevelOrder(BiTNode T);


#endif //CODEEXERCISE_BITREE_H
