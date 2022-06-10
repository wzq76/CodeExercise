//
// Created by wzq12 on 2022-06-09.
//

#include "SqList.cpp"
/**
 * 1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，
 *    若顺序表为空则显示出错信息并退出运行。
 *
 * 算法思想:
 *     搜索整个顺序衰，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
 */
bool Del_Min(SqList &l,ElemType &value){
    if (l.length==0) return false;
    int i,index;
    value = l.data[0];
    for (i = 0; i < l.length; ++i) {
        if (l.data[i]<value){
            value = l.data[i];
            index = i;
        }
    }
    l.data[index] = l.data[l.length-1];
    l.length--;
    return true;
}