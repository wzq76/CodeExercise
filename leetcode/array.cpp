//
// Created by wzq12 on 2022-06-10.
//
#include <vector>
using namespace std;
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




int main() {
};

