//
// Created by wzq12 on 2022-06-10.
//
#include <iostream>
#include <string>
#include "binarySearch.cpp"
#include "insertSort.cpp"
#include "QuickSort.cpp"
#include "ShellSort.cpp"
#include "MergeSort.cpp"
#include "HeapSort.cpp"


int main() {
//    vector<int> v1 = {6, 2, 3, 7, 4, 8, 9, 1, 5};
//    cout << v1.data() << endl;
//    cout<< binarySearch(v1,3);
//    InsertSort(v1);
//    InsertSort2(v1);
//    ShellSort(v1, 9);
//    QuickSort(v1,0,8);
//    for (int &v: v1) {
//        cout << v << ' ';
//    }
    int a[] = {0,2,4,6,8,1,3,5,7};
//    MergeSort(a,0,7);
    HeapSort(a,8);
    for (int &v: a) {
        cout << v << ' ';
    }
}
