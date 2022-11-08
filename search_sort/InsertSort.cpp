//
// Created by wzq12 on 2022-07-20.
//

#include <iostream>
#include "vector"

using namespace std;
/**
 * 直接插入排序 n n^2 n^2 稳定
 * 每次将一个待排序的记录按其关键字大小插入到前面己排好序的子序列中，直到全部记录插入完成。
 * (1) 从前面的有序子表中查找出待插入元素应该被插入的位置;
 * (2) 给插入位置腾出空间，将待插入元素复制到表中的插入位置。
 */
void InsertSort(vector<int> &vec) {
    int i, j, val;
    for (i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            val = vec[i];       // 若小于其前驱, 插入有序表
            for (j = i - 1; val < vec[j] && j >= 0; --j) vec[j + 1] = vec[j]; //待插入元素小于比较元素，大元素向后覆盖
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