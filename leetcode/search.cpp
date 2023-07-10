//
// Created by wzq12 on 2023/6/29.
//
#include <vector>

using namespace std;

/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * @param nums
 * @param target
 * @return
 */
int binarySearch(vector<int> &nums, int target, bool flag) {
    int left = 0, right = nums.size() - 1, ans = nums.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (flag && nums[mid] >= target)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int left = binarySearch(nums, target, true);
    int riht = binarySearch(nums, target, false) - 1;
    if (left <= riht && riht < nums.size() && nums[left] == target && nums[riht] == target) {
        return vector<int>{left, riht};
    }
    return vector<int>{-1, -1};
}

/**
 * 35. 搜索插入位置
 * @param nums
 * @param target
 * @return
 */
int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (middle > target) {
            right = middle - 1;
        } else if (middle < target) {
            left = middle + 1;
        } else return middle; //在数组中间位置插入middle会等于left和right
    }
    //如果在0位置插入right会一直左移在-1时退出
    //如果在末尾位置插入left会在nums.size()时退出
    return right + 1;
}
/**
 * 69. x 的平方根
 * @param x
 * @return
 */
int mySqrt(int x) {
    int i=0,j=x,ans=-1;
    while (i<=j){
        int mid = (i+j)/2;
        if ((long long) mid * mid <= x) {
            ans=mid;
            i=mid+1;
        } else{
            j=mid-1;
        }
    }
    return ans;
}

/**
 * 704. 二分查找
 * @param nums
 * @param target
 * @return
 * 当left==right，区间[left, right]有效
 */

int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] < target) {
            left = middle + 1;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else return middle;
    }
    return -1;

}
