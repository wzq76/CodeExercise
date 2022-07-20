//
// Created by wzq12 on 2022-07-20.
//
#include "vector"
using namespace std;

/**
 * 面试题 17.10. 主要元素 摩尔投票
 * @param nums
 * @return
 */
int majorityElement(vector<int> &nums) {
    int candidate = -1;
    int count = 0;
    for (int &num: nums) {
        if (count == 0) candidate = num; //剩下一个没有被抵消掉的
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    int len = nums.size();
    for (int &num: nums) {  //验证得票过半
        if (num == candidate) count++;
    }
    return count * 2 > len ? candidate : -1;
}