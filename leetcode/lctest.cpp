//
// Created by wzq12 on 2022-07-20.
//
#include "iostream"
#include "vector"
#include "array.cpp"

using namespace std;

int majorityElement(vector<int> &nums) {
    int candidate = -1;
    int count = 0;
    for (int &num: nums) {
        if (count == 0) candidate = num;
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    int len = nums.size();
    for (int &num: nums) {
        if (num == candidate) count++;
    }
    return count * 2 > len ? candidate : -1;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    for(auto const& value : nums)
        cout << value << "; ";
};
