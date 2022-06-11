//
// Created by wzq12 on 2022-06-09.
//

#include "ch02exercise.cpp"
#include <vector>
#include <iostream>
using namespace std;
void init(SqList &l,vector<int> v,int n){
    for (int i = 0; i < n; ++i) {
        l.data[i] = v[i];
    }
    l.length = n;
}

int main(){
    int n;
    vector<int> v1 = {1,3,5,7,9};
    vector<int> v2 = {2,4,6,8};
    SqList l1;
    SqList l2;
    InitList(l1);
    InitList(l2);
    init(l1,v1,5);
    init(l2,v2,4);
    PrintList(l1);
    PrintList(l2);
// 1
//    Del_Min(l1, n);
//    cout<<n<<endl;
//    PrintList(l1);
//2
//    PrintList(l1);
//    Reverse(l1);
//    PrintList(l1);
//3
//    del_x_2(l1,4);
//    PrintList(l1);
//4
//    Del_s_t(l1,3,7);
//    PrintList(l1);
//5
//    Del_s_t2(l1,3,7);
//    PrintList(l1);
//6
//    Delete_Same(l1);
//    PrintList(l1);
//7
//    SqList l3;
//    InitList(l3);
//    Merge(l1,l2,l3);
//    PrintList(l3);












}