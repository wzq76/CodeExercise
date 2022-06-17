//
// Created by w on 2022/6/19.
//

#include <cstdlib>
#include "SqStack.h"

void InitStack(SqStack &s){
    s.top = -1;
}

bool StackEmpty(SqStack sqStack){
    return sqStack.top == -1;
}

bool Push(SqStack &s,ElemType x){
    if(s.top >= MaxSize-1){
        return false;
    }
    s.data[++s.top];
    return true;
}
bool Pop(SqStack &s,ElemType &x){
    if(s.top == -1){
        return false;
    }
    x = s.data[s.top--];
    return true;
}

bool GetTop(SqStack &s,ElemType &x){
    if(s.top == -1){
        return false;
    }
    x = s.data[s.top];
    return true;
}
void DetroyStack(SqStack &s){
    free(s.data);
    s.top = -1;
}

