//
// Created by wzq12 on 2023/6/27.
//
#include <string>
#include <vector>
using namespace std;
/**
 * 14. 最长公共前缀
 * @param strs
 * @return
 */
string longestCommonPrefix(vector<string>& strs) {
    string str = "";
    for (int i = 0; i < strs[0].size(); ++i) {
        char x = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j][i]!= x) {
                return str;
            }
        }
        str += x;
    }
    return str;
}