//
// Created by wzq12 on 2022-06-09.
//
#include "SqList.h"

/*
 * 初始化线性表
 */
bool InitList(SqList &l) {
    l.data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
    l.length = 0;
}

/*
 * 表长度
*/
int Length(SqList l) {
    return l.length;
}

/*
 * 安值查找
 */
int LocateElem(SqList l, ElemType e) {
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == e)
            return i + 1;//下标i 位序i+1
    }
    return 0;
}

/*
 * 按位查找
 */
ElemType GetElem(SqList l, int i) {
    if (i < 1 || i > l.length)
        return -1;
    return l.data[i - 1];
}

/*
 * 在第i位插入
 */
bool ListInsert(SqList &l, int i, ElemType e) {
    if (i < 1 || i > l.length) return false;
    if (l.length >= MaxSize) return false;

    for (int j = l.length; j >= i; --j)
        l.data[j] = l.data[j - 1];
    l.data[i - 1] = e;
    l.length++;
    return true;
}

/*
 * 删除第I个位置元素
 */
bool ListDelete(SqList &l, int i, ElemType &e) {
    if (i < 1 || i > l.length)
        return false;
    if (l.length == 0) return false;

    e = l.data[i - 1];
    for (int j = i; j < l.length; ++j) {
        l.data[j - 1] = l.data[j];
    }
    l.length--;
    return true;
}

/*
 * 打印元素
 */
void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        std::cout << l.data[i] << ' ';
    }
    std::cout << std::endl;
}

/*
 * 判空
 */
bool Empty(SqList l) {
    return l.length == 0;
}

/*
 * 销毁
 */
bool DestroyList(SqList &l) {
    free(l.data);
    l.length = 0;
    return true;
}

