//
// Created by wzq12 on 2022-11-10.
//

#include <vector>

using namespace std;

/**
 * 堆排序 nlong nlong nlong n 不稳定
 * 算法思想:
 *    首先将存放在 L[1..n] 中的 n 个元素建成初始堆，由于堆本身的特点(以大顶堆为例)，堆顶元素就是最大值。
 *    输出堆顶元素后，通常将堆底元素送入堆顶，此时根结点已不满足大顶堆的性质，堆被破坏，将堆顶元素向下调整
 *    使其继续保持大顶堆的性质，再输出堆顶元素。如此重复，直到堆中仅剩一个元素为止。
 */
void HeadAdjust(int a[], int k, int len) {
    a[0] = a[k];                         //k为待调整父节点位置，i为子节点
    for (int i = 2 * k; i <= len; i *= 2) { //子节点i下标为父节点k*2
        if (i + 1 <= len && a[i + 1] > a[i]) i++; //筛选两个子节点中较大的

        if (a[0] > a[i]) {
            break;  //父节点大，堆不变化
        } else {
            a[k] = a[i]; //父节点小,尝试将父节点继续向下调整
            k = i;
        }
    }
    a[k] = a[0];
}

void BuildMaxHeap(int a[], int len) {//注意: 数组从1开始(比较容易定位孩子节点)
    for (int i = len / 2; i > 0; i--)
        HeadAdjust(a, i, len);
}


void HeapSort(int a[], int n) {
    BuildMaxHeap(a, n); //初始建立大根堆
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);   //输出队顶元素调整剩余的元素成大根堆
        HeadAdjust(a, 1, i - 1);
    }
}