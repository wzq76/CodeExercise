//
// Created by wzq12 on 2022-06-17.
//

#include <iostream>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 203
 * @param head
 * @param val
 * @return
 */
ListNode *removeElements(ListNode *head, int val) {
    ListNode *l = new ListNode(0, head);//虚拟头节点
    ListNode *cur = l; // 当前元素指针,判断下一个元素是否要删除
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    head = l->next;
    delete l;
    return head;
}


