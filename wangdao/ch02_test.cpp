//
// Created by wzq12 on 2022-06-09.
//

#include "ch02/ch02exercise.cpp"
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
    vector<int> v1 = {9,8,6,4,5,7};
    SqList l1;
    InitList(l1);
    init(l1,v1,6);
    PrintList(l1);

// 1
//    Del_Min(l1, n);
//    cout<<n<<endl;
//    PrintList(l1);
//2





















}