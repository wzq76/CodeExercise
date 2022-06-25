//
// Created by wzq12 on 2022-06-24.
//

#include "BiTree.cpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int indent = 85;
    string str = "12#46##7##3#5##";
    const char* elems = str.data();    // 先序遍历 建二叉树线序
    BiTree r;
    Create(r,elems);
//    PreOrder22(r);
//    test(r);
//    InOrder22(r);
    PostOrder22(r);
}