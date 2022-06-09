//
// Created by wzq12 on 2022-06-08.
//

#ifndef CODEEXERCISE_SQLIST_H
#define CODEEXERCISE_SQLIST_H

#include <iostream>
#include <cstdlib>
using namespace std;

#define MaxSize 50
/*
 * 线性表定义
 */
typedef int ElemType;
typedef struct SqList{
    ElemType* data;
    int Length;
}SqList;
/*
 * 线性表基本操作
 */
bool InitList(SqList &L);
int Length(SqList l);
ElemType GetElem(SqList l,int i);
bool ListInsert(SqList &l,int i,ElemType e );
bool ListDelete(SqList &l,int i,ElemType &e);
void PrintList(SqList l);
bool Empty(SqList l);
bool DestroyList(SqList &l);

#endif //CODEEXERCISE_SQLIST_H
