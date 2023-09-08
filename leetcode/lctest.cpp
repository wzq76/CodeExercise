//
// Created by wzq12 on 2022-07-20.
//
#include "iostream"
#include "vector"
#include "array.cpp"
#include <string>
#include "DivideConquer.cpp"
//#include "BiTree.cpp"

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

//int main() {
////    vector<int> nums = {2, 0, 2, 1, 1, 0};
////    sortColors(nums);
////
////    for(auto const& value : nums)
////        cout << value << "; ";
//    vector<string> strs = {"flower", "flow", "flight"};
////    cout<< strs[0][0];
//    cout << longestCommonPrefix(strs);
//
//    string str = "1234 5678";
//    for (string::reverse_iterator itr = str.rbegin(); itr != str.rend(); ++itr)
//        cout << *itr;
//
//
//};
#include <iostream>

using namespace std;

int main(void) {
//    int a, b = 5;
//    (a = b) = 10;
//    cout << "a = " << a << " b = " << b << endl;
//    (a < b ? a : b) = 200;
//    cout << "a = " << a << " b = " << b << endl;
//    return 0;
//    TreeNode * p2 = new TreeNode(2,NULL, NULL);
//    TreeNode * p3 = new TreeNode(3,NULL, NULL);
//    TreeNode * p1 = new TreeNode(1, p2,p3);
//
//    TreeNode * q2 = new TreeNode(2, NULL, NULL);
//    TreeNode * q3 = new TreeNode(3,NULL, NULL);
//    TreeNode * q1 = new TreeNode(1, q2,q3);
//
//    cout<< isSameTree1(p1,q1);
    vector<int> res{1, 2, 3, 4, 5};
    vector<int> res1(res.begin(), res.end());
    for (const auto &item: res1) {
        cout<<item;
    }
//    cout << *(res.end()-1);

}
