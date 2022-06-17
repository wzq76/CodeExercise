//
// Created by wzq12 on 2022-06-10.
//
#include <vector>
using namespace std;


/**
 * 26
 * @param nums
 * @return
 */
int removeDuplicates(vector<int>& nums) {
    int slow=0;
    for (int fast = 1; fast < nums.size(); ++fast) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
    }
    return slow+1;
}
/**
 * 27
 * @param nums
 * @param val
 * @return
 */
int removeElement(vector<int>& nums, int val) {
    int slow=0;
    for (int fast = 0; fast < nums.size(); ++fast) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}


/**
 * 35
 * @param nums
 * @param target
 * @return 返回右下标加1是插入位置
 */


int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while (left<=right){
        int middle = (left+right)/2;
        if (nums[middle] > target) {
            right = middle-1;
        }else if (nums[middle] < target) {
            left = middle +1;
        }else return middle;
    }
    return right+1;
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
 * 704
 * @param nums
 * @param target
 * @return
 */
int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (right + left) / 2;
        if (nums[middle] > target) {
            right = middle-1;
        }else if (nums[middle]< target) {
            left = middle+1;
        }else return middle;
    }
    return -1;
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




int main() {
};

