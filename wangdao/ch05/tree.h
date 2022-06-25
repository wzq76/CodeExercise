//
// Created by wzq12 on 2022-06-23.
//

#ifndef CODEEXERCISE_TREE_H
#define CODEEXERCISE_TREE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MaxSize 100
using namespace std;
/**
 * 双亲表示法 parent-1表示根
 */

typedef char ElemType;

typedef struct PTNode {
    ElemType data;
    int parent;
}PTNode;

typedef struct PTree{
    PTNode nodes[MaxSize];
    int n;
}PTree;

/**
 * 孩子表示法
 */
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}*ChildPtr;
typedef struct
{
    ElemType data;
    ChildPtr firstchild; //指向孩子的指针
}CTBox;
typedef struct
{
    CTBox nodes[MaxSize];
    int n,r; //结点数和根结点的位置
}CTree;


/**
 * 孩子兄弟法（二叉树表示法）：树转二叉树
 */

#define maxNodes
typedef struct CSNode{
    ElemType data;
    CSNode *firstChild,*nextSibling;
}CSNode,CSTree;

void display(CSNode *node);


#endif //CODEEXERCISE_TREE_H
