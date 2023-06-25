//
// Created by wzq12 on 2022-07-20.
//
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 面试题 02.07. 链表相交
 * @param headA
 * @param headB
 * @return
 */
//    交点不是数值相等，而是指针相等。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA;
    ListNode *curB = headB;
    int lenA = 0, lenB = 0;
    while (curA != nullptr) { // 求链表A的长度
        lenA++;
        curA = curA->next;
    }
    while (curB != nullptr) { // 求链表B的长度
        lenB++;
        curB = curB->next;
    }
    curA = headA; //重置
    curB = headB;
    if (lenB > lenA) {
        swap(lenA, lenB);
        swap(curA, curB);
    }
    int gap = lenA - lenB;
    // 让curA和curB在同一起点上（末尾位置对齐）
    while (gap--) {
        curA = curA->next;
    }
    while (curA) {
        if (curA == curB) return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
}

/**
 * 面试题 17.10. 主要元素 摩尔投票
 * @param nums
 * @return
 */
int majorityElement(vector<int> &nums) {
    int candidate = -1;
    int count = 0;
    for (int &num: nums) {
        //第一个为候选者，与候选者相同投一票不同减一票，票数为零新选下个为候选人
        if (count == 0) candidate = num;
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    int len = nums.size();
    for (int &num: nums) {  //验证得票过半为主要元素
        if (num == candidate) count++;
    }
    return count * 2 > len ? candidate : -1;
}