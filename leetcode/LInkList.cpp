//
// Created by wzq12 on 2022-06-17.
//

#include <iostream>
#include <vector>
#include <queue>
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
 * 2. 两数相加
 * @param l1
 * @param l2
 * @return
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode * head = new ListNode(-1),*p=head;
    int sum = 0;        //两位相加求和
    bool flag = false;  //进位标志
    while(l1 || l2){
        sum = 0;
        if (l1) {
            sum+=l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum+=l2->val;
            l2=l2->next;
        }
        if (flag) sum++;    //如果上次运算有进位
        p->next = new ListNode(sum%10);//取一位
        p = p->next;
        flag = sum>9? true: false;
    }
    if (flag) {             //如果最后一次运算有进位，新开一位
        p->next=new ListNode(1);
    }
    return head->next;
}


/**
 * 19 删除倒数第n个
 * @param head
 * @param n
 * @return
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *slow = dummyHead, *fast = dummyHead; //双指针，快指针先走n+1步
    while (n >= 0 && fast) {
        fast = fast->next;
        n--;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}

/**
 * 21. 合并两个有序链表
 * @param list1
 * @param list2
 * @return
 */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1), *p = dummy;
    ListNode *p1 = list1, *p2 = list2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val > p2->val) {
            p->next = p2;
            p2 = p2->next;
        } else {
            p->next = p1;
            p1 = p1->next;
        }
        p = p->next;
    }
    if (p1 != NULL) {
        p->next = p1;
    }
    if (p2 != NULL) {
        p->next = p2;
    }
    return dummy->next;
}
/**
 * 23. 合并K个升序链表
 * @param lists
 * @return
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    ListNode * dummy = new ListNode(-1),*p=dummy;
    priority_queue<ListNode,vector<ListNode>,greater<ListNode>> q;
    for (auto head:lists) {
        if (head != nullptr) {
            q.push(head);
        }
    }
    while (!q.empty()){
        ListNode * node = q.top();
    }
}
/**
 * 24 两两交换链表中的结点
 * @param head
 * @return
 */
ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *cur = dummyHead; //cur两个待交换节点的前节点
    while (cur->next && cur->next->next) {
        ListNode *temp = cur->next;
        cur->next = cur->next->next;
        temp->next = cur->next->next;
        cur->next->next = temp;
        cur = temp;
    }
    return dummyHead->next; //如果返回head，head还是指向1
}

/**
 * 83. 删除排序链表中的重复元素
 * @param head
 * @return
 */
ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) return head;
    ListNode * p=head;
    while (p->next){
        if (p->val == p->next->val) {
            p->next = p->next->next;
        }else{
            p= p->next;
        }
    }
    return head;
}

/**
 * 86. 分隔链表
 * @param head
 * @param x
 * @return
 */
ListNode *partition(ListNode *head, int x) {
    ListNode *p = head;
    //xiao
    ListNode *dummyH1 = new ListNode(-1), *p1 = dummyH1;
    //da
    ListNode *dummyH2 = new ListNode(-1), *p2 = dummyH2;

    while (p != nullptr) {
        if (p->val >= x) {
            p2->next = p;
            p2 = p2->next;
        } else {
            p1->next = p;
            p1 = p1->next;
        }
        ListNode *t = p->next;
        p->next = nullptr;
        p=t;
    }
    p1->next = dummyH2->next;
    return dummyH1->next;

}

/**
 * 141. 环形链表
 */
bool hasCycle(ListNode *head) {
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast!= nullptr && fast->next!= nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}

/**
 * 142. 环形链表
 * @param head
 * @return
 */
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {             //相遇
            ListNode *index1 = fast;    //从相遇点遍历
            ListNode *index2 = head;    //从头开始遍历
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index2;
        }
    }
    return nullptr;
}

/**
 * 143. 重排链表
 */
void reorderList(ListNode *head) {

}

/**
 * 160. 相交链表
 * @param headA
 * @param headB
 * @return
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1=headA;
    ListNode* p2=headB;
    while(p1!=p2){
        if (p1 == nullptr) {
            p1->next=headB;
        }else p1=p1->next;
        if (p2 == nullptr) {
            p2->next=headA;
        }else p2=p2->next;
    }
    return p1;

}


/**
 * 203
 * @param head
 * @param val
 * @return
 */
ListNode *removeElements(ListNode *head, int val) {
    ListNode *l = new ListNode(0, head);    //虚拟头节点,方便删除头节点
    ListNode *cur = l;          // 当前元素指针,判断下一个元素是否要删除
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    head = l->next; // 更新头节点
    delete l;
    return head;
}

/**
 * 206. 反转链表
 */
//摘下头节点进行头部插入
ListNode *reverseList(ListNode *head) {
    ListNode *_dummyHead = new ListNode(0, head);
    ListNode *p = _dummyHead->next, *q;
    _dummyHead->next = nullptr;
    while (p) {
        q = p->next;
        p->next = _dummyHead->next;
        _dummyHead->next = p;
        p = q;
    }
    return _dummyHead->next;
}

//双指针反转，注意空指针可能随机指向某处
ListNode *reverseList2(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *temp;
    while (cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

/**
 * 234. 回文链表
 * @param head
 * @return
 */
bool isPalindrome(ListNode *head) {

}

/**
 * 707 设计链表
 */
//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;

        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

// 注意index是从0开始的，第0个节点就是头结点
// _size是容量，(_size-1)是下标
    int get(int index) {
        if (index > (_size - 1) || index < 0) return -1;
        LinkedNode *cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则置为0，作为链表的新头节点。
    void addAtIndex(int index, int val) {
        if (index > _size || index < 0) return;
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        LinkedNode *cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    void printLinkedList() {
        LinkedNode *cur = _dummyHead;
        while (cur) {
            cout << cur->next->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};

/**
 * 876. 链表的中间节点
 * @param head
 * @return
 */
ListNode* middleNode(ListNode* head) {
    ListNode * slow = head;
    ListNode * fast = head;
    while(fast && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}