//
// Created by wzq12 on 2022-06-14.
//
#include "LinkList.h"

LinkList List_HeadInsert(LinkList &l, int a[], int n) {
    l = (LNode *) malloc(sizeof(LNode));
    l->next = NULL;
    LNode *s;
    for (int i = 0; i < n; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        s->next = l->next;
        l->next = s;
    }
    return l;
}

/**
 * 尾插法
 * @param l
 * @param a
 * @param n
 * @return
 */
LinkList List_TailInsert(LinkList &l, int a[], int n) {
    l = (LNode *) malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;

    LNode *s;
    LNode *r = l;
    for (int i = 0; i < n; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return l;
}

/**
 * 按位置查找
 */
LNode *GetElem(LinkList l, int i) {
    if (i < 0) {
        return NULL;
    }
    int k = 0;
    while (l && k < i) {
        l = l->next;
        k++;
    }
    return l;
}

/**
 * 按值查找
 * @param l
 * @param e
 * @return
 */
LNode *LocateElem(LinkList l, Elemtype e) {
    l = l->next;
    while (l) {
        if (l->data == e) {
            break;
        }
        l = l->next;
    }
    return l;
}

/**
 * 获取长度
 * @param l
 * @return
 */
int Length(LNode *l) {
    int length = 0;
    LNode *p = l->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

void PrintLinkList(LinkList l) {
    l = l->next;
    while (l) {
        std::cout << l->data << ' ';
        l = l->next;
    }
    std::cout << std::endl;
}








