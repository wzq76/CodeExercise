//
// Created by wzq12 on 2022-06-24.
//

#include "BiTree.h"
#include "vector"

using namespace std;

/**
 * 19.【2014 统考真题】 二又树的带权路径长度( WPL )是二又树中所有叶结点的带权路径长度之和。
 *     给定一棵二叉树 T，采用二叉链表存储，结点结构为 left  weight  right, 其中叶结点的 weight 域保存该结点的非负权值 。
 *     设 root 为指向 T 的根结点的指针， 请设计求 T的 WPL 的算法。
 * 算法思路:
 *     (1) 若该结点是叶结点，则计算该结点的深度与权值之积。
 *     (2) 若该结点是非叶结点， 则左子树不为空时，对左子树调用递归算法，右子树不为空，对右子树调用递归算法，深度均为本结点的深度加 1。
 *     (3) 最后返回计算出的 wpl 即可。
 */
void Wpl(BiTree t, int dep, int &sum) {
    if (t == nullptr) return;
    if (t->lchild == NULL && t->rchild == NULL) sum += dep * t->data;
    Wpl(t->lchild, dep + 1, sum);
    Wpl(t->rchild, dep + 1, sum);
}

int WplSum(BiTree T, int depth, int &sum) {
    sum = 0;
    Wpl(T, 0, sum);
    return sum;
}

/**
 * 20.【2017 统考真题】请设计一个算法，将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
 *     例如，当下列两棵表达式树作为算法的输入时:
 *     输出的等价中缀表达式分别为(a+b)*(c女(-d))和(a*b)+(- (c-d))
 * 算法思想:
 *     表达式树的中序序列加上必要的括号即为等价的中缀表达式。可以基于二叉树的中序遍历策略得到所需的表达式。
 */
void BtreeToExp(BiTree T, int depth){
    if(!T)return;
    if (T->lchild == nullptr && T->rchild == nullptr) {
        cout<<T->data;
    } else{
        if (depth > 1) cout<<'(';
        BtreeToExp(T->lchild,depth+=1);
        cout<<T->data;
        BtreeToExp(T->rchild,depth+=1);
        if(depth>1) cout<<')';
    }
}

/**
 * 【2022 统考真题】T中不存在的结点在数组SqBiTNode中用-1表示。
 * 请设计一个尽可能高效的算法，判定一棵采用这种方式存储的二叉树是否为二叉搜索树，若是，则返回true，否则，返回false，要求：
⑴ 给出算法的基本设计思想。
⑵ 根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
 */
typedef struct {                    // MAX_SIZE为已定义常量
    int SqBiTNode[1000];   // 保存二叉树结点值的数组
    int ELemNum;                    // 实际占用的数组元素个数
} SqBiTree;

void traversal(SqBiTree root, int i, vector<int> &vec) {
    if (i >= root.ELemNum || root.SqBiTNode[i] == -1) return;// 越界或者为空结点
    traversal(root, 2 * i + 1, vec);
    vec.push_back(root.SqBiTNode[i]);
    traversal(root, 2 * i + 2, vec);
}

bool isValidBST(SqBiTree root) {
    vector<int> vec;
    traversal(root, 0, vec);
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) return false;
    }
    return true;
}
