//
// Created by wzq12 on 2022-11-08.
//
#include <vector>

using namespace std;

/**
 * 希尔排序
 *
 * 先将待排序表分割成若干形如 L[i, i+d, i+2d,..., i+kd] 的“特殊” 子表，即把相隔某个"增量"的记录组成一个子表，
 *  对各个子表分别进行直接插入排序，当整个表中的元素呈“基本有序”时，再对全体记录进行一次直接插入排序。
 */
void ShellSort(vector<int> &A, int n) {
    int i, j, val, d;

    for (d = n / 2; d >= 1; d /= 2) {
        for (i = d; i < n; i++) {
            // 所有距离为d的倍数的记录放在同一组，在各组内进行直接插入排序;
            if (A[i] < A[i - d]) {                        // 需将 A[i] 插入有序增量子表
                val = A[i];
                for (j = i - d; j >= 0 && val < A[j]; j -= d)
                    A[j + d] = A[j];                  // 记录后移， 查找插入的位置
                A[j + d] = val;
            }
        }
    }
}