//
// Created by wzq12 on 2022-11-08.
//
#include "vector"

/**
 * 快速排序 nlogn nlogn n^2 不稳定
 *在待排序表 L[1...n] 中任取一个元素 pivot 作为枢轴(或基准，通常取首元素)，通-过一趟排序，将待排序表划分为独立的两部分
 *L[1...k-1]和L[k+1...n],使得 L[1...k-1] 中的所有元素小于 pivot,L[k+1...n] 中的所有元素大于等于 pivot，
 * 则 pivot 放在了其最终位置 L(k)上，这个过程称为一趟快速排序(或一次划分)。
 * 然后分别递归地对两个子表重复上述过程，直至每部分内只有一个元素或空为止，则所有元素放在了其最终位置上。
 */
int partition(vector<int> &a, int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;                         //枢轴元素存放到最终位置
    return low;
}

void QuickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pivot_pos = partition(a, low, high);
        QuickSort(a, low, pivot_pos - 1);
        QuickSort(a, pivot_pos + 1, high);
    }
}