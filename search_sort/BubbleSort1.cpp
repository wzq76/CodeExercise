//
// Created by wzq12 on 2022-11-08.
//
#include <vector>

using namespace std;
/**
 * 冒泡排序
 *
 * 算法思想:
 * 从后往前(或从前往后)两两比较相邻元素的值，
 * 若为逆序(即 A[i-1]>A[i])，则交换它们，直到序列比较完。
 */
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort1(vector<int> A[] , int n){  // 从后往前 -> 关键字最小的元素如气泡-般逐渐往上“漂浮”直至“水面”
    bool flag;

    for(int i=0;i<n-1;i++){             // 理解为每趟冒泡确定的位置
        flag = false;                   // 表示本趟冒泡是否发生交换的标志
        for(int j=n-1;j>i;j--){         // 一趟冒泡过程
            if(A[j-1]>A[j]){
                swap(A[j-1], A[j]);
                flag = true;
            }
        }
        if(!flag)                       // 本趟遍历后没有发生交换，说明表已经有序
            return;
    }
}

void BubbleSort2(vector<int> A[],int n){   // 从前往后 -> 关键字最大的元素如石头一般下沉至水底

    bool flag;
    for(int i=n-1; i>0; i--){
        flag = false;
        for(int j=0; j<i; j++){
            if(A[j]>A[j+1]){
                swap(A[j], A[j+1]);
                flag = true;
            }
        }
        if(!flag)                       // 本趟遍历后没有发生交换，说明表已经有序
            return;
    }
}