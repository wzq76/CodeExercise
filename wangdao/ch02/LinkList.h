//
// Created by wzq12 on 2022-06-14.
//

#ifndef CODEEXERCISE_LINKLIST_H
#define CODEEXERCISE_LINKLIST_H



#include <iostream>

using namespace std;

typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode* next;
}LNode,*LinkList;

/**
* 单链表基本操作
*/
LinkList List_HeadInsert(LinkList &l,int a[],int n);
LinkList List_TailInsert(LinkList &l,int a[],int n);
LNode *GetElem(LinkList l,int i);
LNode *LocateElem(LinkList l,Elemtype e);
void PrintLinkList(LinkList l);
int Length(LinkList l);

/**
* 双链表
*/
typedef struct DNode{
    Elemtype data;
    struct DNode *prior,*next;

    int freq;
}DNode,*DLinkList;



#endif //CODEEXERCISE_LINKLIST_H













