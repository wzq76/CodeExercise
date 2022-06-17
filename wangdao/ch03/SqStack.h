//
// Created by w on 2022/6/19.
//

#ifndef CODEEXERCISE_SQSTACK_H
#define CODEEXERCISE_SQSTACK_H

#define MaxSize 100
/**
 * stack
 */

typedef int ElemType;
typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;

/**
 * 栈的基本操作
 */
void InitStack(SqStack &S);         // 初始化一个空栈
bool StackEmpty(SqStack S);         // 判断一个栈是否为空， 若找 s 为空则返回 true，否则返回 false。
bool Push(SqStack &S, ElemType x);  // 进栈，若栈 s 未满，则将 x 压入栈
bool Pop(SqStack &s, ElemType &x);  // 出栈，若栈 S 非空，则弹出栈顶元素， 并用 x 返回。
bool GetTop(SqStack S, ElemType &x);// 读栈顶元素，若栈 s 非空，则用 x 返回栈顶元素。
void DestroyStack(SqStack&S);       // 销毁栈，并释放栈 s 占用的存储空间(“&” 表示引用调用)。
bool StackOverflow(SqStack S);      // 判断栈是否满
int StackLength(SqStack S);         // 栈元素个数




#endif //CODEEXERCISE_SQSTACK_H
