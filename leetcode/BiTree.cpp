
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
    TreeNode *cur = root; //指针的遍历访问节点，栈则用来处理节点上的元素

    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
            st.push(cur);
            cur = cur->left;  //先找最左孩子
        } else {
            cur = st.top(); //指针回溯栈顶元素
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

/**
 * 98.验证二叉搜索树
 */
vector<int> vec;

void traversal(TreeNode *root) {
    if (root == NULL) return;
    traversal(root->left);
    vec.push_back(root->val);
    traversal(root->right);
}

bool isValidBST(TreeNode *root) {
//    vec.clear();
    traversal(root);
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] <= vec[i - 1]) return false;
    }
    return true;
}


/**
 * 101 对称二叉树
 * @param left
 * @param right
 * @return
 */
//递归法
bool compare(TreeNode *left, TreeNode *right) {
    //中止条件：左右有空节点的情况
    if (left == NULL && right != NULL) return false;
    else if (left != NULL && right == NULL) return false;
    else if (left == NULL && right == NULL) return true;
        //中止条件：左右没有空节点的情况:左右不同值就退出 左右相同值就递归
    else if (left->val != right->val)return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    bool isSame = outside && inside;
    return isSame;
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) return true;
    return compare(root->left, root->right);
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
    order(cur->left, result, depth + 1);
    order(cur->right, result, depth + 1);
}

vector<vector<int>> levelOrder2(TreeNode *root) {
    vector<vector<int>> result;
    int depth = 0;
    order(root, result, depth);
    return result;
}

/**
 * 107 自底向上层序遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrderBottom(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) que.push(root);
    vector<vector<int>> result;

    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = que.front();
            vec.push_back(node->val);
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    reverse(result.begin(), result.end());
    return result;
}

/**
 * 112. 路径总和
 * @param cur
 * @param count
 * @return
 */
bool traversal(TreeNode *cur, int count) {
    // 如果是叶子，并且计数为0
    if (cur->left == nullptr && cur->right == nullptr && count == 0)return true;
    if (cur->left == nullptr && cur->right == nullptr && count != 0) return false;

    if (cur->left) { //左孩子存在向左递归
        count -= cur->left->val;
        if (traversal(cur->left, count)) return true;
        count += cur->left->val; //向左递归结果不符合条件回溯
    }
    if (cur->right) {
        count -= cur->right->val;
        if (traversal(cur->right, count)) return true;
        count += cur->right->val;
    }
    return false;
}

bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    return traversal(root, targetSum - root->val);
}

/**
 * 144 二叉树前序遍历
 * @param root
 * @return vector
 */
vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;

    if (root == NULL) return result;
    st.push(root);       //处理顺序和访问顺序一致
    while (!st.empty()) {
        TreeNode *node = st.top(); //处理栈顶
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
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    reverse(result.begin(), result.end());
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
TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//迭代法 前序遍历或者层序遍历都行
TreeNode *invertTree2(TreeNode *root) {
    stack<TreeNode *> st;
    if (root) st.push(root);

    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        swap(node->left, node->right);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return root;
}

/**
 * 637 二叉树层平均值
 * @param root
 * @return
 */
vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) que.push(root);
    vector<double> result;

    while (!que.empty()) {
        int size = que.size();
        double evl = 0;

        for (int i = 0; i < size; ++i) {
            TreeNode *node = que.front();
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








