//
// Created by wzq12 on 2022-06-10.
//
#include <vector>

using namespace std;

/**
* [left,right],[left,right)
 *
*/
int binarySearch(vector<int> &a, int target) {
    int left = 0;
    int right = a.size() - 1; //定义target在左闭右闭的区间里，[left, right]
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] > target) {
            right = middle - 1; // [left,right]
        } else if (a[middle] < target) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}