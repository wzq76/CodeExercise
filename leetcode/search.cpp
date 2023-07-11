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
    int i = 0, j = x, ans = -1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if ((long long) mid * mid <= x) {
            ans = mid;
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return ans;
}

/**
 * 74. 搜索二维矩阵
 * @param matrix
 * @param target
 * @return
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        int x = matrix[mid / n][mid % n];
        if (x < target) {
            left = mid + 1;
        } else if (x > target) {
            right = mid - 1;
        }else return true;
    }
    return false;
}
/**
 * 153. 寻找旋转排序数组中的最小值
 * @param nums
 * @return
 */
int findMin(vector<int>& nums) {

}
/**
 * 162. 寻找峰值
 * @param nums
 * @return
 */
int findPeakElement(vector<int>& nums) {

}
/**
 * 167. 两数之和 II - 输入有序数组
 * @param numbers
 * @param target
 * @return
 */
vector<int> twoSum(vector<int>& numbers, int target) {

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
