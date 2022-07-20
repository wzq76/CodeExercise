//
// Created by wzq12 on 2022-07-20.
//

#include <iostream>
#include "vector"

using namespace std;

void InsertSort(vector<int> &vec) {
    int i, j, val;
    for (i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            val = vec[i];
            for (j = i - 1; val < vec[j] && j >= 0; --j) vec[j + 1] = vec[j]; //查找，待插入元素小于比较元素，元素向后覆盖
            vec[j + 1] = val; //复制到插入位置，稳定的
        }
    }
}

void InsertSort2(vector<int> &vec) {
    int i, j, val, low, high, mid;
    for (i = 1; i < vec.size(); i++) {
            val = vec[i];
            low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (vec[mid] > val) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            for (j = i - 1; j >=high+1 ; --j) vec[j + 1] = vec[j]; //统一后移元素
            vec[high+1] = val;
    }
}