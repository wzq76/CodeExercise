
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

    TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}

    TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
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

    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;  //先找最左孩子
        } else {
            cur = st.top(); //无左，指针回溯栈顶元素
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}



vector<int> vec;
/***
 * 98.验证二叉搜索树
 * @param root
 * 中序遍历下，输出的二叉搜索树节点的数值是有序序列。
 */

void traversal(TreeNode *root) {
    if (root == nullptr) return;
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
 * 100. 相同的树
 * @param p
 * @param q
 * @return
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    stack<TreeNode*> stack;
    stack.push(p);
    stack.push(q);

    while (!stack.empty()){
        TreeNode* rightnode = stack.top();stack.pop();
        TreeNode* leftnode = stack.top();stack.pop();
        if (!leftnode && !rightnode) continue;  //同时为空
        if ((!rightnode || !leftnode || (rightnode->val != leftnode->val))) return false;
        stack.push(leftnode->left); //比较左节点
        stack.push(rightnode->left);
        stack.push(leftnode->right);//比较右
        stack.push(rightnode->right);
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
    if (left == nullptr && right != nullptr) return false;
    else if (left != nullptr && right == nullptr) return false;
    else if (left == nullptr && right == nullptr) return true;
        //中止条件：左右没有空节点的情况:左右不同值就退出 左右相同值就递归
    else if (left->val != right->val)return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    bool isSame = outside && inside;
    return isSame;
}

bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return compare(root->left, root->right);
}

bool isSameTree1(TreeNode* p, TreeNode* q) {
    stack<TreeNode*> stack;
    stack.push(p);
    stack.push(q);

    while (!stack.empty()){
        TreeNode* rightnode = stack.top();stack.pop();
        TreeNode* leftnode = stack.top();stack.pop();
        if (!leftnode && !rightnode) continue;  //同时为空
        if ((!rightnode || !leftnode || (rightnode->val != leftnode->val))) return false;
        stack.push(leftnode->left);
        stack.push(rightnode->right);
        stack.push(leftnode->right);
        stack.push(rightnode->left);
    }
    return true;
}

/**
 * 102 层序遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);
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
    if (cur == nullptrptr) return;
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
 * 103. 二叉树的锯齿形层序遍历
 * @param root
 * @return
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> queue;
    vector<vector<int>> res;
    if (root) queue.push(root);
    int flag = 1;
    while (!queue.empty()) {
        int size = queue.size();
        vector<int> v;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = queue.front();
            v.push_back(node->val);
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
            queue.pop();
        }
        if (flag % 2 == 0) reverse(v.begin(), v.end());
        flag++;
        res.push_back(v);//偶数层反转
    }
    return res;
}

/***
 * 104. 二叉树的最大深度
 * @param root
 * @return
 */
int getdepth(TreeNode *node) {
    if (node == nullptr) return 0;
    int leftdepth = getdepth(node->left);
    int rightdepth = getdepth(node->right);
    int depth = 1 + max(leftdepth, rightdepth);
    return depth;
}
//递归
int maxDepth2(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + max(getdepth(root->right), getdepth(root->left));
}
//迭代，层序遍历层数
int maxDepth(TreeNode *root) {
    if(root== nullptr) return 0;
    int depth=0;
    queue<TreeNode *>queue;
    queue.push(root);
    while(!queue.empty()){
        depth +=1;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            TreeNode * node = queue.front();
            queue.pop();
            if (node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
    }
    return depth;
}
/***
 * 106.从中序与后序遍历序列构造二叉树
 * @param inorder
 * @param postorder
 * @return
 */
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

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
 * 108. 将有序数组转换为二叉搜索树
 * @param nums
 * @return
 */
TreeNode *sortedArrayToBST(vector<int> &nums) {

}
/**
 * 109. 有序链表转换二叉搜索树
 * @param head
 * @return
 */
TreeNode* sortedListToBST(ListNode* head) {

}
/**
 * 110. 平衡二叉树
 * @param root
 * @return
 */
bool isBalanced(TreeNode* root) {

}
/***
 * 111. 二叉树的最小深度
 * @param root
 * @return
 */
int minDepth(TreeNode* root) {

}
/**
 * 112. 路径总和
 * @param cur
 * @param count
 * @return
 */
bool traversal(TreeNode *cur, int count) {
    // 如果是叶子，并且计数为0
    if (cur->left == nullptrptr && cur->right == nullptrptr && count == 0)return true;
    if (cur->left == nullptrptr && cur->right == nullptrptr && count != 0) return false;

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
 * 116.填充每个节点的下一个右侧节点指针
 * @param root
 * @return
 */
Node* connect(Node* root) {

}

/**
 * 117.填充每个节点的下一个右侧节点指针II
 * @param root
 * @return
 */
Node* connect(Node* root) {

}
/**
 * 144 二叉树前序遍历
 * @param root
 * @return vector
 */
vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;

    if (root == nullptrptr) return result;
    st.push(root);       //处理顺序和访问顺序一致
    while (!st.empty()) {
        TreeNode *node = st.top(); //处理栈顶
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);//先进栈的后出
        if (node->left) st.push(node->left);
    }
    return result;
}

/**
 * 145.二叉树后序遍历
 * @param root
 * @return
 */
vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;
    if (root == nullptr) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(result.begin(), result.end());
    return result;
}

/**
 * 199.二叉树的右视图：判断每层的最后一个节点
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

/***
 * 222.完全二叉树的节点个数
 * @param root
 * @return
 */
int countNodes(TreeNode* root) {

}
/**
 * 226 反转二叉树
 * @param root
 * @return
 */

// 递归法
TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return root;
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
        st.pop();                           //立即出栈
        swap(node->left, node->right);//中
        if (node->right) st.push(node->right);//已经左右交换的左
        if (node->left) st.push(node->left);//右
    }
    return root;
}

/**
 * 230. 二叉搜索树中第K小的元素
 * @param root
 * @param k
 * @return
 */
int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode* >stack;
    TreeNode *cur = root;
    vector<int> res;
    int res_k=0;
    while (cur != nullptr || !stack.empty()){   //中序遍历取第K个
        if (cur != nullptr) {
            stack.push(cur);
            cur = cur->left;
        }else{
            cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
    if(res.size()>0) res_k = res[k-1];
    return res_k;
}

/**
 * 235. 二叉搜索树的最近公共祖先
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

}

/**
 * 236. 二叉树的最近公共祖先
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

}

/***
 * 257. 二叉树的所有路径
 * @param root
 * @return
 */
vector<string> binaryTreePaths(TreeNode* root) {

}
/***
 * 404. 左叶子之和
 * @param root
 * @return
 */
int sumOfLeftLeaves(TreeNode *root) {

}

/***
 * 429.N叉树的层序遍历
 * @param root
 * @return
 */
vector<vector<int>> levelOrder(Node* root) {

}

/**
 * 450.删除二叉搜索树中的节点
 * @param root
 * @param key
 * @return
 */
TreeNode* deleteNode(TreeNode* root, int key) {

}

/**
 * 501.二叉搜索树中的众数
 * @param root
 * @return
 */
vector<int> findMode(TreeNode* root) {

}

/***
 * 513.找树左下角的值
 * @param root
 * @return
 */
int findBottomLeftValue(TreeNode* root) {

}
/**
 * 515.在每个树行中找最大值
 * @param root
 * @return
 */
vector<int> largestValues(TreeNode* root) {

}

/**
 * 530.二叉搜索树的最小绝对差
 * @param root
 * @return
 */
int getMinimumDifference(TreeNode* root) {

}

/**
 * 538.把二叉搜索树转换为累加树
 * @param root
 * @return
 */
TreeNode* convertBST(TreeNode* root) {

}

/***
 * 559.n叉树的最大深度
 * @param root
 * @return
 */
int maxDepth(Node* root) {
    queue<Node*> queue;
    if(root != nullptr) queue.push(root);
    int depth = 0;
    while (!queue.empty()){
        depth += 1;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node * node = queue.front();
            queue.pop();
            for (int j = 0; j < node->children.size(); ++j) {
                queue.push(node->children[j]);
            }
        }
    }
    return depth;
}

/**
 * 617.合并二叉树
 * @param root1
 * @param root2
 * @return
 */
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

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
/**
 * 654.最大二叉树
 * @param nums
 * @return
 */
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

}

/**
 * 669. 修剪二叉搜索树
 * @param root
 * @param low
 * @param high
 * @return
 */
TreeNode* trimBST(TreeNode* root, int low, int high) {

}

/**
 * 700.二叉搜索树中的搜索
 * @param root
 * @param val
 * @return
 */
TreeNode* searchBST(TreeNode* root, int val) {

}

/**
 * 701.二叉搜索树中的插入操作
 * @param root
 * @param val
 * @return
 */
TreeNode* insertIntoBST(TreeNode* root, int val) {

}

/**
 * 958. 二叉树的完全性检验
 * @param root
 * @return
 */
bool isCompleteTree(TreeNode *root) {

}







