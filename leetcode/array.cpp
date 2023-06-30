//
// Created by wzq12 on 2022-06-10.
//
#include <vector>

using namespace std;

/**
 * 9. 回文数
 * @param x
 * @return
 */
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    long int temp = x, y = 0;
    while (temp > 0) {
        int last = temp % 10;
        y = y * 10 + last;
        temp = temp / 10;
    }
    return x == y;
}

/**
 * 26
 * @param nums
 * @return
 * 慢指针指向没重复元素，快指针向后判断
 */
int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[slow] != nums[i]) {
            nums[++slow] = nums[i];
        }
    }
    return slow + 1;
}

/**
 * 27. 移除元素
 * @param nums
 * @param val
 * @return
 * 双指针，fast用来判断，slow用来确定数组中的值
 */
int removeElement(vector<int> &nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * @param nums
 * @param target
 * @return
 */
vector<int> searchRange(vector<int>& nums, int target) {

}

/**
 * 35
 * @param nums
 * @param target
 * @return 返回右下标加1是插入位置
 */


int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else return middle;
    }
    return right + 1;
}

/**
 * 59 螺旋矩阵
 * @param n
 * @return
 */
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0)); //定义初始化结果矩阵
    int startx = 0, starty = 0; //起点(0,0)
    int loop = n / 2; //循环圈数
    int mid = n / 2; //如果是奇数，剩余中间位置要填充
    int count = 1;
    int offset = 1; //每圈偏移量
    int i, j;
    while (loop--) {
        i = startx;
        j = starty;
        for (j = starty; j < n - offset; j++) {// 模拟填充上行从左到右[左闭右开)
            res[i][j] = count++;
        }
        for (i = startx; i < n - offset; i++) {
            res[i][j] = count++;
        }
        for (; j > starty; j--) {
            res[i][j] = count++;
        }
        for (; i > startx; i--) {
            res[i][j] = count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if (n % 2 == 1) {
        res[mid][mid] = count;
    }
    return res;
}

/**
 * 75. 颜色分类
 * @param nums
 */
void sortColors(vector<int> &nums) {
    int q = 0, p = 0;
    int flag = 0;
    while (q < nums.size()) {
        if (p <= nums.size() && nums[p] == flag) {
            swap(nums[q++], nums[p++]);
        } else {
            p++;
        }
        if (p >= nums.size() && flag < 2) {
            flag++;
            p = q;
        }
    }

}

/**
 * 88. 合并两个有序数组
 * @param nums1
 * @param m
 * @param nums2
 * @param n
 * 从后往前合并
 */
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (!n)
        return;
    int i = m - 1, j = n - 1;
    int p = nums1.size() - 1;//总数量
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[p--] = nums1[i--];
        } else {
            nums1[p--] = nums2[j--];
        }
    }
    while (j >= 0) {//数组二剩余
        nums1[p--] = nums2[j--];
    }

}


/**
 * 977
 * @param nums
 * @return
 */
vector<int> sortedSquares(vector<int> &nums) {
    vector<int> result(nums.size(), 0);
    int i, j, k = nums.size();
    for (i = 0, j = nums.size() - 1; i <= j;) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            result[--k] = nums[i] * nums[i];
            i++;
        } else {
            result[--k] = nums[j] * nums[j];
            j--;
        }
    }
    return result;
}





