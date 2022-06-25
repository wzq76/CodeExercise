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
    const char* elems = str.data();    // 构建二叉树
    BiTree r;
    Create(r,elems);
    PreOrder2(r);

}