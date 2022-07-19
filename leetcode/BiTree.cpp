
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * 94 二叉树中序遍历
 * @param root
 * @return
 */
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode* cur = root; //指针的遍历访问节点，栈则用来处理节点上的元素

    while (cur!=NULL || !st.empty()){
        if (cur!= NULL) {
            st.push(cur);
            cur = cur->left;
        } else{
            cur = st.top(); //指针回溯栈顶元素
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

/**
 * 102 层序遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;

    while (!que.empty()) {
        int size = que.size(); //每一层节点数都是变化的，本次循环个数取决于上轮入队数
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = que.front();
            vec.push_back(node->val);
            que.pop();
            if (node->left) que.push(node->left); //队首节点孩子入队
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}
/**
 * 递归法
 * @param cur
 * @param result
 * @param depth
 */
void order(TreeNode *cur, vector<vector<int>> &result, int depth) {
    if (cur == nullptr) return;
    if (result.size() == depth) result.push_back(vector<int>());
    result[depth].push_back(cur->val);
    order(cur->left,result,depth+1);
    order(cur->right,result,depth+1);
}

vector<vector<int>> levelOrder2(TreeNode *root) {
    vector<vector<int>> result;
    int depth = 0;
    order(root,result,depth);
    return result;
}
/**
 * 107 自底向上层序遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> que;
    if (root) que.push(root);
    vector<vector<int>> result;

    while (!que.empty()){
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            vec.push_back(node->val);
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    reverse(result.begin(),result.end());
    return result;
}
/**
 * 144 二叉树前序遍历
 * @param root
 * @return vector
 */
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;

    if (root == NULL) return result;
    st.push(root);       //处理顺序和访问顺序一致
    while (!st.empty()){
        TreeNode* node = st.top(); //处理栈顶
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}
/**
 * 二叉树后序遍历
 * @param root
 * @return
 */
vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        if(node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    reverse(result.begin(),result.end());
    return result;
}
/**
 * 199 二叉树的右视图：判断每层的最后一个节点
 * @param root
 * @return
 */

vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) que.push(root);
    vector<int> result;

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = que.front();
            que.pop();

            if (i == (size - 1)) result.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return result;
}
/**
 * 226 反转二叉树
 * @param root
 * @return
 */

 // 递归法
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
//迭代法 前序遍历或者层序遍历都行
TreeNode* invertTree2(TreeNode* root) {
    stack<TreeNode*>st;
    if (root) st.push(root);

    while (!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        swap(node->left,node->right);
        if (node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return root;
}

/**
 * 637 二叉树层平均值
 * @param root
 * @return
 */
vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> que;
    if (root) que.push(root);
    vector<double> result;

    while(!que.empty()){
        int size = que.size();
        double evl=0;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            evl += node->val;
            if (i == (size - 1)) {
                evl /= size;
                result.push_back(evl);
            }
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return result;

}








