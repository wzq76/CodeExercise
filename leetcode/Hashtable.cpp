//
// Created by wzq12 on 2022-08-30.
//
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
/**
 * 41. 缺失的第一个正数
 * @param nums
 * @return
 */
int firstMissingPositive(vector<int>& nums) {

}


/**
 * 242.有效的字母异位词
 * @param s
 * @param t
 * @return
 *
 */
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int record[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        record[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
        record[t[i]-'a']--;
    }
    for (int re: record) {
        if (re!=0) return false;
    }
    return true;
}

/**
 * 349. 两个数组的交集
 * @param nums1
 * @param nums2
 * @return
 */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> result; // 存放结果，之所以用set是为了给结果集去重
    unordered_set<int> nums_set(nums1.begin(),nums1.end());
    for (int num: nums2) {
        if (nums_set.find(num) != nums_set.end()) result.insert(num);
    }
    return vector<int>(result.begin(),result.end());
}