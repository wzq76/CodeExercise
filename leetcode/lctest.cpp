//
// Created by wzq12 on 2022-07-20.
//
#include "iostream"
#include "vector"
using namespace std;

int majorityElement(vector<int> &nums) {
    int candidate = -1;
    int count = 0;
    for (int& num: nums) {
        if (count == 0) candidate = num;
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    int len = nums.size();
    for (int& num: nums) {
        if (num == candidate) count++;
    }
    return count * 2 > len ? candidate : -1;
}

int main(){
    vector<int> nums = {0,5,5,3,5,7,5,5};
    cout<< majorityElement(nums)  <<endl;
}