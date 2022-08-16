//
// Created by wzq12 on 2022-08-16.
//
#include <stack>
#include <queue>
#include <string>
using namespace std;




/**
 * 20 有效括号
 * @param s
 * @return
 */
bool isValid(string s) {
    if (s.size() % 2 != 0) return false;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        //遍历发现左括号，进栈右括号
        if (s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历过程中，栈已经为空了，说明右括号没有找到对应的左括号
            // 第二种情况：遍历字符串匹配的过程中，发现栈里不是我们要匹配的字符
        else if (st.empty() || s[i] != st.top()) return false;
        else st.pop();
    }
    return st.empty();
}


/**
 * 225 用队列实现栈
 */
queue<int> que;

void push(int x) {
    que.push(x);
}

int pop() {
    int size = que.size() - 1;
    while (size--){
        que.push(que.front()); //循环入队实现栈
        que.pop();
    }
    int result = que.front();
    que.pop();
    return result;
}

int top() {
    return que.back();
}

bool empty() {
    return que.empty();
}
/**
 * 232用栈实现队列
 */
stack<int> stIn;
stack<int> stOut;


void push(int x) {
    stIn.push(x);
}

int pop() {
    if (stOut.empty()) {
        while (!stIn.empty()) { //利用两个栈实现队列
            stOut.push(stIn.top());
            stIn.pop();
        }
    }
    int result = stOut.top();
    stOut.pop();
    return result;
}

int peek() {
    int res = this->pop();
    stOut.push(res);
    return res;
}

bool empty() {
    return stIn.empty() && stOut.empty();
}