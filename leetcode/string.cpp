//
// Created by wzq12 on 2023/6/30.
//

#include <string>

using namespace std;

/**
 * 58. 最后一个单词的长度
 * @param s
 * @return
 * rbegin 反向迭代器开头，rend()反向迭代器结尾即字符串开头的前一个位置
 * https://img-blog.csdn.net/20160305203448811
 */
int lengthOfLastWord(string s) {
    auto i = s.rbegin();
    while (*i == ' ')++i;              //单词末尾位置
    auto i1 = s.rbegin();
    while (i1 != s.rend() && *i1 != ' ') ++i1;  //没到开头且不是空格
    return distance(i,i1);
}
