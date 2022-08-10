//
// Created by wzq12 on 2022-06-09.
//

#include "SqList.cpp"
#include "LinkList.cpp"
#include <stack>
#include "vector"

/**
 * 1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，
 *    若顺序表为空则显示出错信息并退出运行。
 *
 * 算法思想:
 *     搜索整个顺序衰，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
 */
bool Del_Min(SqList &l, ElemType &value) {
    if (l.length == 0) return false;
    int i, index;
    value = l.data[0];
    for (i = 0; i < l.length; ++i) {
        if (l.data[i] < value) {
            value = l.data[i];
            index = i;
        }
    }
    l.data[index] = l.data[l.length - 1];
    l.length--;
    return true;
}

/**
 * 2. 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)。
 * 算法思想: 扫描顺序表L的前半部分元素，对于元素L.data[i) (O<=i<L.length/2),
 *         将其与后半部分的对应元素 L.data[L.length-i-1)进行交换。
 */
void Reverse(SqList &l) {
    if (l.length == 0) return;
    ElemType t;
    for (int i = 0; i < l.length / 2; ++i) {
        t = l.data[i];
        l.data[i] = l.data[l.length - i - 1];
        l.data[l.length - i - 1] = t;
    }
}

/**
* 3. 对长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)、空间复杂度为 O(1) 的算法，该算法删除线性表中所有值为 x 的数据元素。
* 算法思想: 用 k 记录顺序表 L 中等于 x 的元素个数，边扫描 L 边统计 k，并将不等于 x 的元素前移 k 个位置，最后修改 L 的长度。
*/
void del_x_2(SqList &l, ElemType x) {
    if (l.length == 0) return;
    int n = 0;
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == x) {
            n++;
        } else {
            l.data[i - n] = l.data[i]; // 当前元素向前覆盖n位
        }
    }
    l.length -= n;
}

/**
 * 4. 从有序顺序表中删除其值在给定值s与t之间(要求s小于t) 的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * 算法思想: 先寻找值大于等于 s 的第一个元素(第一个删除的元素)， 然后寻找值大于 t 的第一个元素(最后一个删除的元素的下一个元素)，
 *          要将这段元素删除，只需直接将后面的元素前移。
 */
bool Del_s_t(SqList &l, ElemType s, ElemType t) {
    if (l.length == 0 || s >= t) return false;

    int i, j;
    for (i = 0; i < l.length && l.data[i] <= s; ++i); //查找元素
    if (i >= l.length) return false;
    for (j = i; j < l.length && l.data[j] < t; ++j);
    for (; j < l.length; ++j, ++i) {
        l.data[i] = l.data[j];
    }
    l.length = i;
    return true;
}

/**
 * 5. 从顺序表中删除其值在给定值s与t之间(包含s和t,要求s小于t) 的所有元素， 如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * 算法思想:
 *    从前向后扫描顺序表 L，用 k 记录下元素值在s与t之间元素的个数(初始时 k=0)。
 *    对于当前扫描的元素，若其值不在 s 到 t 之间，则前移 k 个位置; 否则执行 k++。
 */
bool Del_s_t2(SqList &l, ElemType s, ElemType t) {
    if (l.length == 0 || s >= t) return false;
    int k = 0;
    for (int i = 0; i < l.length; ++i) {
        if (s <= l.data[i] && l.data[i] <= t) {
            k++;    // 符合【s,t】的个数
        } else {
            l.data[i - k] = l.data[i];
        }
    }
    l.length -= k;
    return true;
}

/**
 * 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 * 算法思想: (类似于直接插入排序)
 *    有序顺序表值相同的元素一定在连续的位置上，用类似于直接插入排序的思想。
 *    初始时将第一个元素视为非重复的有序表, 之后依次判断后面的元素是否与前面非重复有序表的最后一个元素相同，
 *    若相同则继续向后判断，若不同则插入到前面的非重复有序表的最后，直至判断到表尾为止。
 */
bool Delete_Same(SqList &l) {
    int i, j;
    for (i = 0, j = 1; j < l.length; ++j) {
        if (l.data[i] != l.data[j]) {
            l.data[++i] = l.data[j];
        }
    }
    l.length = i + 1;
    return true;
}

/**
 * 7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */
bool Merge(SqList a, SqList b, SqList &c) {
    if (a.length + b.length > MaxSize) return false;
    int i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length) {
        if (a.data[i] < b.data[j]) {
            c.data[k++] = a.data[i++];
        } else {
            c.data[k++] = b.data[j++];
        }
    }
    while (i < a.length) c.data[k++] = a.data[i++]; //剩余没合并的合并到末尾
    while (j < b.length) c.data[k++] = b.data[j++];
    c.length = k;
    return true;
}

/**
 * 8. 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,a3,···,am) 和 (b1,b2,b3,···,bn)。
 *    试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,···,bn)放在(a1,a2,a3,···,am)的前面。
 * 10.【2010 统考真题】设将 n(n>1) 个整数存放到一维数组 R 中。设计一个在时间和空间两方面都尽可能高效的算法。
 *     将 R 中保存的序列循环左移 p (O<p<n ) 个位直，即将 R 中的 数据由 (X0,X1,...,Xn-1) 交换为 (Xp,Xp+1,...,Xn-1,X0,X1,Xp-1)。
 */
void ReverseArray(ElemType a[], int l, int r) {
    ElemType tmp;
    for (; l < r; l++, r--) {
        tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
    }
}

void Reverse(ElemType a[], int m, int n) {
    ReverseArray(a, 0, m - 1);
    ReverseArray(a, m, m + n - 1);
    ReverseArray(a, 0, m + n - 1);
}

/**
 * 9. 线性表(a1,a2,a3,···,an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为 x 的元素，
 *    若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
 * 算法思想: 折半查找
 */
void SearchExcgIst(vector<int> &a, int n, ElemType x) {
    int low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (mid < n - 1 && a[mid] == x) {
        ElemType t = a[mid];
        a[mid] = a[mid + 1];
        a[mid + 1] = t;
    }
    if (low > high) { //查找失败
        for (int i = n - 1; i > high; --i) a[i + 1] = a[i];
        a[high + 1] = x;
    }
}

/**
 * 11.【2011】一个长度为L(L>=1)的升序序列S，处在第「L/2 个位置的数称为 S 的中位数 。
 *     例如，若序列 S1 = (11 , 13, 15, 17, 19)，则 S1 的中位数是 15，
 *     两个序列的中位数是含它们所有元素的升序序列的中位数。
 *     例如，若 S2 = (2, 4, 6, 8, 20)，则 S1 和 S2 的中位数是 11。
 *     现在有两个等长升序序列 A 和 B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列 A 和 B 的中位数。
 *
 * 方法1: 双指针 => 等价于求第n个节点
 * 方法2: 分别求两个升序序列 A、 B 的中 位数，设为 a 和 b， 求序列 A、 B 的中位数过程如下:
 *     ① 若 a=b，则 a或b 即为所求中位数，算法结束。
 *     ② 若 a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等。
 *     ③ 若 a>b，则舍弃序列 A 中较大的一半，同时舍弃序列 B 中较小的一半，要求两次舍弃的长度相等。
 *     在保留的两个升序序列中，重复过程1、2、 3，直到两个序列中均只含一个元素时为止，较小者即为所求的中位数。
 */
int MSearch(int a[], int b[], int l) {
    int i = 0, j = 0, median = 0;
    for (int k = 0; k < l; ++k) {
        if (a[i] < b[j]) {
            median = a[i++];
        } else {
            median = b[j++];
        }
    }
    return median;
}

/**
 * 12.【2013】已知一个整数序列 A =(a0，a1，..., an-1)，其中 0≤ai<n (0≤i<n)。 若存在
 *    ap1 = ap2 =...= apm = x 且 m>n/2 (0≤pk<n，1≤k≤m)，则称 x 为 A 的主元素。
 *    例如A= ( 0，5，5，3，5，7，5，5 )，则 5 为主元素；又如 A= ( 0，5，5，3，5，1，5，7 )，
 *    则A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 *    找出 A 的主元素。若存在主元素， 则输出该元素；否则输出-1。
 * 算法思想:
 *     从前向后扫描数组元素，标记出一个可能成为主元素的元素 num。然后重新计数，确认 num 是否是主元素。算法可分为以下两步:
 *     (1)选取候选的主元素。
 *        ① 依次扫描所给数组中的每个整数，记录 num 的出现次数为 1;
 *        ② 遇到的下一个整数仍等于 num，则计数 cnt 加 1， 否则计数减 1:
 *        ③ 当计数减到 0 时，将遇到的下一个整数保存到 num 中，计数重新记为 1，
 *        ④ 开始新一轮计数，即从当前位置开始重复上述过程，直到扫描完全部数组元素 。
 *     (2)判断 num 是否是真正的主元素。再次扫描该数组，统计 num 出现的次数，若大 于 n/2，则为主元素；否则，序列中不存在主元素。
 *
 * https://leetcode-cn.com/problems/find-majority-element-lcci/
 */
int Majority(int a[], int n) {
    if (n < 1) return -1;
    int b[sizeof(a)] = {0};
    for (int i = 0; i < n; ++i) {
        b[a[i]] += 1;
    }
    for (int j = 0; j < n; ++j) {
        if (b[j] > n / 2)
            return j;
    }
    return -1;
}

/**
 * 13.【2018】给定一个含 n (n>=1)个整数的数组，请设计一个在时问上尽可能高效的算法，找出数组中未出现的最小正整数。
 *     例如，数组 {-5，3, 2, 3} 中未出现的最小正整数是1; 数组 {1,2,3} 中未出现的最小正整数是 4。
 * 算法思想:
 *     要求在时间上尽可能高效，因此采用空间换时间的办法。
 *     分配一个用于标记的数组 B[n+1],用来记录A中是否出现了1~n中的正整数，B[O]对应正整数 1, B[n]对应正整数n，初始化B中全部为0。
 *     由于 A 中含有n个整数，因此可能返回的值是1~n:
 *        ① 当 A 中 n 个数恰好为 1~n 时返回 n+1。
 *        ② 当数组 A 中出现了小于等于 0 或大于 n 的值时，会导致 1~n 中出现空余位置，返回结果必然在 1~n 中，
 *           因此对于 A 中 出现了小于等于 0 或大于 n 的值可以不采取任何操作。
 */
int findMissMin(int a[], int n) {
    int b[sizeof(a) + 1] = {0};
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && a[i] <= n) {
            b[a[i]] = 1;
        }
    }
    for (int j = 1; j <= n; ++j) {
        if (b[j] == 0)
            return j;
    }
}

/**
 * 1. 设计一个递归算法, 删除不带头结点的单链表 L 中所有值为 x 的结点。
 *    终止条件: f(L, x)=不做任何事情,                 若 L 为空表
 *    递归主体: f(L, x)=删除*L结点, f(L->next, x);   若 L一>data==x
 */

void Del_X_1(LinkList &l, Elemtype x) {
    LNode *p;
    if (!l) return; //递归出口:
    if (l->data == x) {
        p = l;
        l = l->next;
        free(p);
        Del_X_1(l, x);
    } else {
        Del_X_1(l->next, x);
    }
}

/**
 * 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点 不唯一，试编写算法以实现上述操作。
 * 算法思想:
 *   用 p 从头至尾扫描单链表，pre 指向 *p 结点的前驱。若p所指结点的值为x，则删除，并让p移向下一个结点，否则让pre、p指针同步后移一个结点。
 */
void Del_X_2(LinkList &l, ElemType x) {
    LNode *pre = l, *now = l->next, *q; // pre -> now -> q
    while (now) {
        q = now->next;
        if (now->data == x) {
            pre->next = q;
            delete now;
        } else {
            pre = now;
        }
        now = q;
    }
}

/**
 * 3. 设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。
 * 算法思想:
 *    借助一个辅助栈，每经过一个结点时，将该结点放入栈中。遍历完整个链表后，再从栈顶开始输出结点值即可。
 */

void R_Print(LinkList l) {
    LNode *p = l->next;
    stack<LNode *> s;
    while (p) {
        s.push(p);
        p = p->next;
    }
    while (!s.empty()) {
        cout << s.top()->data << ' ';
        s.pop();
    }
}

/**
 * 4. 试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法(假设最小值结点是唯一的)。
 * 用 p从头至尾扫描单链表，pre指向*p结点的前驱，minp保存值最小的结点指针(初值为p),
 * minpre 指向*minp 结点的前驱(初值为 pre)一边扫描，一边比较，若 p->data 小于 minp->data，
 * 则将 p、 pre 分别赋值给 minp、 minpre，
 * 当 p扫描完毕,minp 指向最小值结点，minpre 指向最小值结点的前驱结点，
 * 再将 minp 所指结点删除即可 。
 */

LinkList Delete_Min(LinkList &l) {
    if (!l || !l->next) return l;

    LNode *pre = l, *p = l->next; //p指针遍历整个链表
    LNode *minpre = pre, *minp = p;
    while (p) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    cout << minp->data << endl;
    minpre->next = minp->next;
    free(minp);
    return l;
}

/**
 * 5. 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为 0(1)。
 *    将头结点摘下，然后从第一结点开始，依次插入到头结点的后面(头插法建立单链)，
 *    直到最后一个结点为止
 */

LinkList Reverse_1(LinkList &l) {
    LNode *p = l->next, *q;
    l->next = NULL;
    while (p) {
        q = p->next;
        p->next = l->next;
        l->next = p;
        p = q;
    }
    return l;
}

/**
 * 6. 有一个带头结点的单链表 L，设计一个算法使其元素递增有序。
 *    采用直接插入排序算法的思想，先构成只含一个数据结点的有序单链表，然后依次扫描单链表中剩下的结点 *p(直至 p==NULL 为止)，
 *    在有序表中通过比较查找插入 *p 的前驱结点 *pre，然后将 *p 插入到 *pre 之后
 */
void Sort(LinkList &l) {
    LNode *p = l->next, *q, *pre;
    l->next = NULL;         //将头摘下
    while (p) {
        q = p->next;
        pre = l;
        while (pre->next && pre->next->data <= p->data)// 找到第一个比*p大的前一个节点
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

/**
 * 7. 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，
 *    删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在) 。
 */
void RangeDelete(LinkList &l, ElemType min, ElemType max) {
    LNode *pre = l, *p = l->next;
    while (p) {
        if (min <= p->data && p->data <= max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
 * 8. 给定 两个单链表，编写算法找出两个链表的公共结点。
 *    使用两个指针 L1，L2 分别指向两个链表 headA，headB 的头结点，然后同时分别逐结点遍历，
 *    当 L1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；
 *    当 L2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
 *    这样，当它们相遇时，所指向的结点就是第一个公共结点。
 * 链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/shuang-zhi-zhen-fa-lang-man-xiang-yu-by-ml-zimingm/
 */
LinkList Search_Lst_Common(LinkList headA, LinkList headB) {
    LinkList L1 = headA->next;
    LinkList L2 = headB->next;

    if (!L1 || !L2) return NULL;
    while (L1 != L2) {
        L1 = (L1 ? L1->next : L2);
        L2 = (L2 ? L2->next : L1);
    }
    return L1;
}

/**
 * 9. 给定一个带表头结点的单链表，设 head 为头指针，结点结构为(data,next), data 为整型元素，next 为指针，试写出算法。
 *    按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间(要求: 不允许使用数组作为辅助空间)。
 */

void MinDelete(LinkList &l) {
    while (l->next) {
        Delete_Min(l);
    }
    free(l);
}

/**
 * 10.将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B，
 *    使得 A 表中含有原表中序号为奇数的元素，而 B 表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 * 算法思想: 设置一个访问序号变量(初值为 0)，每访问一个结点序号自动加1，然后根据序号的奇偶性将结点插入到 A 表或 B 表中。
 *          重复以上操作直到表尾。
 */

LinkList DisCreat_1(LinkList &a) {
    LNode *p = a->next;
    a->next = NULL;

    LNode *b = (LNode *) malloc(sizeof(LNode));//创建一个B节点
    b->next = NULL;
    LNode *pa = a, *pb = b; //两个链表尾指针

    int cnt = 1;
    while (p) {
        if (cnt % 2 != 0) {   //奇数
            pa->next = p;
            pa = p;
        } else {
            pb->next = p;
            pb = p;
        }
        p = p->next;
        cnt++;
    }
    pa->next = NULL;
    pb->next = NULL;
    return b;
}

/**
 * 11.设 C ={a1,b1,a2,b2,...an,bn} 为线性表，采用带头结点的 hc 单链表存放，设计一个就地算法，将其拆分为两个线性表，
 *  使得 A = {a1,a2,··· , an,}, B= {bn,bn-1,...,b2,b1}
 *  算法思想: 采用上题的思路，二者的差别仅在于对 B 表的建立不采用尾插法，
 *  而是采用头插法。
 */

LinkList DisCreate_2(LinkList &a) {
    LNode *p = a->next, *q;
    a->next = NULL;

    LNode *b = (LNode *) malloc(sizeof(LNode));
    b->next = NULL;

    LNode *pa = a; //尾插法尾指针，尾指针最后要设空
    int cnt = 1;
    while (p) {
        q = p->next;    //采用头插法需要设置辅助指针q防断  p为待分解节点
        if (cnt % 2 != 0) {
            pa->next = p;
            pa = p;
        } else {
            p->next = b->next;
            b->next = p;
        }
        p = q;
        cnt++;
    }
    pa->next = NULL;
    return b;
}


/**
 * 12.在一个递增有序的线性表中，有数值相同的元素存在。 若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素，
 *    例如(7, 10, 10, 21, 30, 42, 42, 42, 51, 70) 将变为 (7, 10, 21, 30, 42, 51, 70)。
 * 算法思想: 由于是有序表，所有相同值域的结点都是相邻的。用 p 扫描递增单链表 L，
 *          若 *p 结点的值域等于 *p 后继结点的值域，则删除后者，否则 p 移向下一个结点。
 * 83. 删除排序链表中的重复元素
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
 */
void Del_Same(LinkList &l) {
    LNode *pre = l->next;
    if (!pre) return;

    LNode *p = pre->next, *q;
    while (p) {
        q = p->next;
        if (pre->data == p->data) {
            pre->next = q;
            free(p);
        } else {
            pre = p;
        }
        p = q;
    }
}

/**
 * 13.假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，
 *    并要求利用原来两个单链表的结点存放归并后的单链表。
 * 算法思想: 两个链表已经按元素值递增次序排序，将其合并时，均从第一个结点起进行比较，将小的结点链入链表中，同时后移工作指针。
 *          该问题要求结果链表按元素值递减次序排列，故新链表的建立应该采用头插法。比较结束后，可能会有一个链表非空，此时用头插法
 *          将剩下的结点依次插入新链表中即可。
 */
LinkList MergeList(LinkList La, LinkList Lb) {
    LNode *Lc = (LNode *) malloc(sizeof(LNode));
    Lc->next = NULL;

    LNode *pa = La->next, *pb = Lb->next, *q; //q防断链指针
    while (pa && pb) {
        if (pa->data < pb->data) {
            q = pa->next;
            pa->next = Lc->next;
            Lc->next = pa;
            pa = q;
        } else {
            q = pb->next;
            pb->next = Lc->next;
            Lc->next = pb;
            pb = q;
        }
    }
    if (pa) pb = pa; //统一用pb指针将剩余的插入
    while (pb) {
        q = pb->next;
        pb->next = Lc->next;
        Lc->next = pb;
        pb = q;
    }
    return Lc;
}

/**
 * 14.设A和B是两个单链表(带头结点)，其中元素递增有序。 设计一个算法从A和B中的公共元素产生单链表C，要求不破坏 A、B 的结点。
 * 算法思想: 表 A、 B 都有序，可从第一个元素起依次比较 A、 B 两表的元素，
 *          若元素值不等，则值小的指针往后移，
 *          若元素值相等，则创建一个值等于两结点的元素值的新结点，使用尾插法插入到新的链表中，并将两个原表指针后移一位
 *          直到其中一个链表遍历到表尾。
 */
LinkList Get_Common(LinkList A, LinkList B) {
    LNode *Lc = (LNode *) malloc(sizeof(LNode *));
    LNode *pa = A->next, *pb = B->next, *pc = Lc, *node;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            node = (LNode *) malloc(sizeof(LNode));
            node->data = pa->data;
            pc->next = node;
            pa = pa->next;
            pb = pb->next;
        }
    }
    pc->next = NULL;
    return Lc;
}

/**
 * 15.已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，
 * 求A与B的交集并存放于A链表中。
 */

void UnionAB(LinkList &A, LinkList &B) {
    LNode *pa = A->next, *pb = B->next, *ra, *q;
    A->next = NULL;
    ra = A; //结果链表的尾指针
    while (pa && pb) {
        if (pa->data < pb->data) {
            q = pa;
            pa = pa->next;
            free(q);
        } else if (pa->data < pb->data) {
            q = pb;
            pb = pb->next;
            free(q);
        } else {
            ra->next = pa;      //将pa节点接入结果，pb节点释放
            ra = pa;
            pa = pa->next;

            q = pb;
            pb = pb->next;
            free(pb);
        }
    }
    ra->next = NULL;
    if (pa) pb = pa;
    while (pb) {
        q = pb;
        pb = pb->next;
        free(q);
    }
    free(B);
}

/**
 * 16.两个整数序列 A ={a1,a2,··· , am} 和 B={b1,b2,...,bn} 已经存入两个单链表中,设计一个算法，判断序列 B 是否是序列 A 的连续子序列。
 * 算法思想:
 *    从两个链表的第一个结点开始，若对应数据相等，则后移指针;
 *    若对应数据不等，则 A 链表从上次开始比较结点的后继开始，B链表仍从第一个结点开始比较，
 *    直到B链表到尾表示匹配成功；A链表到尾而B链表未到尾表示失败。
 */
int Pattern(LinkList A, LinkList B) {
    LNode *prea = A, *pa = A, *pb = B;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
        } else {
            pb = B;
            prea = prea->next;
            pa = prea;
        }
    }
    return pb == NULL ? 1 : 0;
}

/**
 * 17.设计一个算法用于判断带头结点的循环双链表是否对称。
 * 算法思想: 让 p 从左向右扫描， q 从右向左扫描，直到它们指向同一结点
 *          若它们所指结点值相同，则继续进行下去，否则返回 0。若比较全部相等，则返回 1。
 */

int Symmetry(DLinkList L) {
    DNode *p = L->next, *r = L->prior;
    while (p != r && p->next != r) {
        if (p->data == r->data) {
            p = p->next;
            r = r->prior;
        } else {
            return 0;
        }
    }
    return 1;
}

/**
 * 18.有两个循环单链表，链表头指针分别为 h1 和 h2，
 * 编写一个函数将链表 h2 链接到链表 h1 之后 要求链接后的链表仍保持循环链表形式。
 * 算法思想: 先找到两个链表的尾指针，将第一个链表的尾指针与第二个链表的头结点链接起来，再使之成为循环的。
 */
LinkList Link(LinkList &h1, LinkList &h2) { // 无头结点
    LNode *p1 = h1, *p2 = h2;
    while (p1->next != h1) p1 = p1->next;
    while (p2->next != h2) p2 = p2->next;
    p1->next = h2;
    p2->next = h1;
    return h1;
}

/**
 * 19.设有一个带头结点的循环单链表，其结点值均为正整数。
 * 设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，
 *    直到单链表空为止，再删除表头结点。
 */
void Del_All(LinkList &L) {
    while (L->next) {
        Delete_Min(L);
    }
    free(L);
}

/**
 * 20.设头指针为 L 的带有表头结点的非循环双向链表，其每个结点中除有 pred(前驱指针)、data(数据)和 next(后继指针)域外，
 *    还有一个访问频度域 freq。在链表被启用前，其值均初始化为零。每当在链表中进行一次 Locate(L,x)运算时，令元素值为 x
 *    的结点中 freq 域的值增 1，并使此链表中结点保持按访问频度非增(递减)的顺序排列，同时最近访问的结点排在频度相同的结点
 *    前面，以便使频繁访问的结点总是靠近表头。试编写符合上述要求的 Locate(L,x) 运算的算法，该运算为函数过程，返回找到结
 *    点的地址，类型为指针型。
 * 算法思想: 首先在双向链表中查找数据值为 x 的结点，查到后，将结点从链表上摘下，然后再顺着结点的前驱链查找该结点的
 *          插入位置(频度递减，且排在同频度的第一个，即向前找到第一个比它的频度大的结点，插入位置为该结点之后)，并插入到该位置 。
 */


DLinkList Locate(DLinkList &L, ElemType x) {
    DNode *p = L->next, *q, *pre = L;
    while (p && p->data != x)p = p->next; //用p指针查找x节点

    if (!p) return NULL;
    p->freq += 1;

    if (p->next) { //将p摘下准备插入
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
    q = p->prior;
    while (q != L && q->freq <= p->freq)q = q->prior;
    //q是头节点或者是第一个频度比他大的节点
    p->next = q->next;
    q->next->prior = p;
    p->prior = q;
    q->next = p;

    return p;
}

/**
 * 21.「2009」已知一个带有表头结点的单链表，结点结构为 |data|link|，假设该链表只给出了头指针 list。
 *     在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第 k 个位直上的结点(k为正整数)。
 *     若查找成功，算法输出该结点的 data 域的值，并返回1；否则，只返回0。
 * 算法思想:
 *     定义两个指针变量 pre 和 p，初始时均指向头结点的下一个结点(链表表的第一个结点)， p 指针沿链表移动;
 *     当 p 指针移动到第 k 个结点时， pre 指针开始与 p 指针同步移动;
 *     当 p 指针移动到最后一个结点时， pre 指针所指示结点为倒数第 k个结点。
 */
int Search_k(LinkList list, int k) {
    LNode *pre = list->next, *p = list->next;
    while (p) {
        if (k > 0) {
            k--;
        } else {
            pre = pre->next;
        }
        p = p->next;
    }
    if (k == 0 && pre) {
        cout << pre->data << endl;
        return 1;
    }
    return 0;

}

/**
 * 22.【2012】假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，
 *例如，“loading”和“being”的存储映像如下图所示。设 str1 和 str2 分别指向两个单词所在单链表的头结点，
 *链表节点结构为 |data|next|，请设计一个时间上尽可能高效的算法，找出由 str1 和 str2 所指向两个链表共同后缀的起始位置。
 *算法思想: 采用双指针法。
 *用指针 p1、p2 分别扫描 str1 和 str2，当 p1、p2 指向同一个地址时，即找到共同后缀的起始位置。
 */

LNode *find_addr(LNode *str1, LNode *str2) {
    LNode *p1 = str1->next, *p2 = str2->next;
    if (!p1 || !p2) return NULL;
    while (p1 != p2) {
        p1 = p1 ? p1->next : p2;
        p2 = p2 ? p2->next : p1;
    }
    return p1;
}

/**
 * 23.【2015】用单链表保存 m 个整数，结点的结构为 [data][link]，且 |data|<=n (n 为正整数)。现要求设计一个时间复杂度尽可能高效的算法，
 *     对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
 * 算法思想: 用空间换时间。
 *     使用辅助数组记录链表中已出现的数值，从而只需对链表进行一趟扫描。因为 |data|<=n，故辅助数组 q 的大小为 n+1，各元素的初值均为 0。
 *     依次扫描链表中的各结点，同时检查 q[|data|] 的值，若为 0 则保留该结点，井令 q[ldatal]=1；否则将该结点从链表中删除。
 */

void func(LNode *&h, int n) {
    int tag[n + 1];
    for (int i = 0; i <= n; ++i)tag[i] = 0;
    LNode *p = h->next, *pre = h, *q;
    while(p){
        ElemType e = p->data>0?p->data:-p->data;
        if (tag[e] == 0) {
            tag[e] = 1;
            pre->next = p;
            pre=p;
            p=p->next;
        }else{
            q = p;
            p = p->next;
            free(q);
        }
    }
    pre->next = NULL;
}

/**
 * 24.设计一个算法完成以下功能:判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回 NULL。
 * 算法思想:
 *  1. 判断链表中是否有环：
 *    设置快慢两个指针分别为 fast 和 slow，初始时都指向链表头 head。
 *    ① 即 slow=slow->next; fast每次走两步，即 fast=fast->ηext->next。
 *    ② 由于 fast 比 slow 走得快，如果有环，fast 一定会先进入环，而 slow 后进入环。
 *    ③ 当两个指针都进入环后，经过若干次操作后两个指针定能在环上相遇。即可判断一个链表是否有环。
 *
 *  2. 设头结点到环的入口点的距离为 a，环的入口点沿着环的方向到相遇点的距离为 x，环长为 r，相遇时 fast 绕过了 n 圈。
 *     则 2(a+x)=a+nr+x
 *        => a=nr-x=(r-x)+(n-1)r，即从头结点到环的入口点的距离等于 n 倍的环长减去环的入口点到相遇点的距离。
 *     因此可设置两个指针，一个指向head，一个指向相遇点，两个指针同步移动(均为一次走一步)，相遇点即为环的入口点。
 * https://leetcode-cn.com/problems/linked-list-cycle/
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
 */


/**
 * 25.【2019】设线性表 L = {a1,a2,··· ,an},采用带头结点的单链表保存，请设计一个空间复杂度为 O(1) 且时间上尽可能高效的算法，
 *     重新排列 L 中的各结点，得到线性表 L2 = {a1,an,a2,an-1,a3,an-2,···}。
 * 算法思想:
 *      先将 L后半段原地逆置 [题目要求空间复杂度为 0(1)，不能借助栈]，否则每取最后一个结点都需要遍历一次链表。
 *       ① 先找出链表L的中间结点，为此设置两个指针p和q，
 *          指针p每次走一步，指针 q 每次走两步，当指针 q 到达链尾时，指针 p 正好在链表的中间结点
 *       ② 然后将 L 的后半段结点原地逆置。
 *       ③ 从单链表前后两段中依次各取一个结点
 * https://leetcode-cn.com/problems/middle-of-the-linked-list
 */
