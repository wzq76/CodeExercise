//
// Created by wzq12 on 2023/6/30.
//

#include <string>

using namespace std;

/**
 * 58. 最后一个单词的长度
 * @param s
 * @return
 * rbegin 反向迭代器开头，rend()反向迭代器结尾
 */
int lengthOfLastWord(string s) {
    auto i = s.rbegin();
    while (*i == ' ')++i;
    auto i1 = s.rbegin();
    while (i1 != s.rend() && *i1 != ' ') ++i1;
    return distance(i,i1);
}