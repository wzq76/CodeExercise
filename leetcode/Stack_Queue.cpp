//
// Created by wzq12 on 2022-08-16.
//
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
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
 * 150. 逆波兰表达式求值
 * @param tokens
 * @return
 */
int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (tokens[i] == "+") st.push(num2 + num1); //注意num1顺序
            if (tokens[i] == "-") st.push(num2 - num1);
            if (tokens[i] == "*") st.push(num2 * num1);
            if (tokens[i] == "/") st.push(num2 / num1);
        }else {
            st.push(stoi(tokens[i]));
        }
    }
    int result = st.top();
    st.pop();
    return result;
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

/**
 * 1047. 删除字符串中的所有相邻重复项
 * @param s
 * @return
 */
string removeDuplicates(string s) {
    stack<char> st;
    for (char sc :s ) {
        if (st.empty() || sc!=st.top()) {
            st.push(sc);
        } else{
            st.pop(); // sc 与 st.top()相等的情况消除
        }
    }
    string result="";
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}
//拿string直接当作栈用
string removeDuplicates1(string S) {
    string result;
    for(char s : S) {
        if(result.empty() || result.back() != s) {
            result.push_back(s);
        }
        else {
            result.pop_back();
        }
    }
    return result;
}