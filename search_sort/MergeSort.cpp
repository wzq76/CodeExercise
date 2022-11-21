//
// Created by wzq12 on 2022-11-10.
//

#include <vector>
#include <cstdlib>

#define MaxSize 100

using namespace std;
/**
 * 归并排序 nlong nlong nlong n 稳定
 * 算法思想:
 *    (1) 分解
 *        将含有 n 个元素的待排序表分成各含 n/2 个元素的子表，采用 2 路归井排序算法对两个子表递归地进行排序 。
 *    (2) 合并
 *        Merge() 的功能是将前后相邻的两个有序表归并为一个有序表。
 *        设两段有序表 A[low...mid]、 A[mid+l...high] 存放在同一顺序表中的相邻位置，先将它们复制到辅助数组 B 中。每次从对应 B 中的
 *        两个段取出一个记录进行关键字的比较，将较小者放入 A 中， 当数组 B 中有一段的下标超出其对应的表长
 *        (即该段的所有元素都己复制到 A 中)时，将另一段中的剩余部分直接复制到 A 中。
 */
int *b = (int *) malloc((MaxSize + 1) * sizeof(int));

void Merge(int a[], int low, int mid, int high) {
    for (int i = low; i <= high; ++i) b[i] = a[i]; //复制数组合并到原数组
    int i, j, k = 0;
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) {
            a[k] = b[i++];    // 比较 B 的左右两段中的元素,将较小值复制到 A 中
        } else {
            a[k] = b[j++];
        }
    }
    while (i <= mid) a[k++] = b[i++];
    while (j <= high) a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // 从中间划分两个子序列
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}


