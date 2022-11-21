//
// Created by wzq12 on 2022-11-10.
//

#include <iostream>
#include "vector"

/**
 * 选择排序 n^2 n^2 n^2 不稳定
 *
 *每一趟(如第i趟)在后面 n-i+1个待排序元素中选取关键字最小的元素，
 * 作为有序子序列的第 i 个元素，
 *直到第 n-1 趟做完，待排序元素只剩下 1 个，就不用再选了。
 */

void SelectSort(int a[], int n) {
    int j,min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min]<a[j]) {
                min = j;
            }
        }
        if(min != j) std::swap(a[i],a[min]);
    }
}