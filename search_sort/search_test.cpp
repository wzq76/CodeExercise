//
// Created by wzq12 on 2022-06-10.
//
#include <iostream>
#include "binarySearch.cpp"
#include "insertSort.cpp"

int main() {
    vector<int> v1 = {6,2,3,7,4,8,9,1,5};
//    cout<< binarySearch(v1,3);
//    InsertSort(v1);
    InsertSort2(v1);

    for (int &v: v1) {
        cout << v << ' ';
    }
}
