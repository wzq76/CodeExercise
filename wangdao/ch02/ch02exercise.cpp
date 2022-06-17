//
// Created by wzq12 on 2022-06-09.
//

#include "SqList.cpp"
#include "LinkList.cpp"
/**
 * 1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，
 *    若顺序表为空则显示出错信息并退出运行。
 *
 * 算法思想:
 *     搜索整个顺序衰，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
 */
bool Del_Min(SqList &l,ElemType &value){
    if (l.length==0) return false;
    int i,index;
    value = l.data[0];
    for (i = 0; i < l.length; ++i) {
        if (l.data[i]<value){
            value = l.data[i];
            index = i;
        }
    }
    l.data[index] = l.data[l.length-1];
    l.length--;
    return true;
}
/**
 * 2. 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)。
 * 算法思想: 扫描顺序表L的前半部分元素，对于元素L.data[i) (O<=i<L.length/2),
 *         将其与后半部分的对应元素 L.data[L.length-i-1)进行交换。
 */
 void Reverse(SqList &l){
    if (l.length == 0) {
        return;
    }
    ElemType t;
    for (int i = 0; i < l.length / 2; ++i) {
        t = l.data[i];
        l.data[i] = l.data[l.length - i - 1];
        l.data[l.length - i - 1]=t;
    }
 }
/**
* 3. 对长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)、空间复杂度为 O(1) 的算法，该算法删除线性表中所有值为 x 的数据元素。
* 算法思想: 用 k 记录顺序表 L 中等于 x 的元素个数，边扫描 L 边统计 k，并将不等于 x 的元素前移 k 个位置，最后修改 L 的长度。
*/
void del_x_2(SqList &l,ElemType x){
    if (l.length == 0) {
        return;
    }
    int n=0;
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == x) {
            n++;
        }else{
            l.data[i-n] = l.data[i]; // 当前元素前移n
        }
    }
    l.length -= n;
}

/**
 * 4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t) 的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * 算法思想: 先寻找值大于等于 s 的第一个元素(第一个删除的元素)， 然后寻找值大于 t 的第一个元素(最后一个删除的元素的下一个元素)，
 *          要将这段元素删除，只需直接将后面的元素前移。
 */
bool Del_s_t(SqList &l,ElemType s,ElemType t){
    if (l.length == 0 || s >= t) {
        return false;
    }
    int i,j;
    for (i = 0; i < l.length && l.data[i]<=s; ++i) ;
    if (i>=l.length) return false;
    for (j = i; j < l.length && l.data[j]<t ; ++j);
    for (; j < l.length; ++j,++i) {
        l.data[i] = l.data[j];
    }
    l.length = i;
    return true;
}

/**
 * 5. 从顺序表中删除其值在给定值s与t之间(包含s和t,要求s<t) 的所有元素， 如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * 算法思想:
 *    从前向后扫描顺序表 L，用 k 记录下元素值在s与t之间元素的个数(初始时 k=0)。
 *    对于当前扫描的元素，若其值不在 s 到 t 之间，则前移 k 个位置; 否则执行 k++。
 */
bool Del_s_t2(SqList &l,ElemType s,ElemType t){
    if (l.length == 0 || s >= t) {
        return false;
    }
    int k=0;
    for (int i = 0; i < l.length; ++i) {
        if (s <= l.data[i] && l.data[i]<=t) {
            k++;    // 符合【s,t】的个数
        }else{
            l.data[i-k] = l.data[i];
        }
    }
    l.length -=k;
    return true;
}

/**
 * 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 * 算法思想: (类似于直接插入排序)
 *    有序顺序表值相同的元素一定在连续的位置上，用类似于直接插入排序的思想。
 *    初始时将第一个元素视为非重复的有序表, 之后依次判断后面的元素是否与前面非重复有序表的最后一个元素相同，
 *    若相同则继续向后判断，若不同则插入到前面的非重复有序表的最后，直至判断到表尾为止。
 */
bool Delete_Same(SqList& l) {
    int i,j;
    for (i = 0,j = 1; j < l.length; ++j) {
        if (l.data[i] != l.data[j]) {
            l.data[++i] = l.data[j];
        }
    }
    l.length = i+1;
    return true;
}

/**
 * 7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */
bool Merge(SqList a, SqList b, SqList &c){
    if (a.length + b.length > MaxSize) {
        return false;
    }
    int i = 0,j=0,k=0;
    while (i<a.length && j<b.length){
        if (a.data[i]<b.data[j]) {
            c.data[k++] = a.data[i++];
        }else{
            c.data[k++] = b.data[j++];
        }
    }
    while (i<a.length) c.data[k++] = a.data[i++]; //剩余没合并的合并到末尾
    while (j<b.length) c.data[k++] = b.data[j++];
    c.length = k;
    return true;
}

/**
 * 8. 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,a3,···,am) 和 (b1,b2,b3,···,bn)。
 *    试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,···,bn)放在(a1,a2,a3,···,am)的前面。
 * 10.【2010 统考真题】设将 n(n>1) 个整数存放到一维数组 R 中。设计一个在时间和空间两方面都尽可能高效的算法。
 *     将 R 中保存的序列循环左移 p (O<p<n ) 个位直，即将 R 中的 数据由 (X0,X1,...,Xn-1) 交换为 (Xp,Xp+1,...,Xn-1,X0,X1,Xp-1)。
 */
void ReverseArray(ElemType a[],int l,int r){
    ElemType tmp;
    for (; l < r; l++,r--) {
        tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
     }
}

void Reverse(ElemType a[],int m,int n){
    ReverseArray(a,0,m-1);
    ReverseArray(a,m,m+n-1);
    ReverseArray(a,0,m+n-1);
}
/**
 * 9. 线性表(a1,a2,a3,···,an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为 x 的元素，
 *    若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
 * 算法思想: 折半查找
 */

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
int MSearch(int a[],int b[],int l){
    int i=0,j=0,median=0;
    for (int k = 0; k < l; ++k) {
        if (a[i]<b[j]) {
            median=a[i++];
        }else{
            median=b[j++];
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
int Majority(int a[],int n){
    if(n<1) return -1;
    int b[sizeof(a)]={0};
    for (int i = 0; i < n; ++i) {
        b[a[i]] += 1;
    }
    for (int j = 0; j < n; ++j) {
        if (b[j] > n/2)
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
int findMissMin(int a[],int n){
    int b[sizeof(a)+1]={0};
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && a[i]<=n) {
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

void Del_X_1(LinkList &l,Elemtype x){
    LNode *p;
    if (!l) return; //递归出口
    if (l->data == x) {
        p = l;
        l = l->next;
        free(p);
        Del_X_1(l,x);
    }else{
        Del_X_1(l->next,x);
    }
}

/**
 * 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点 不唯一，试编写算法以实现上述操作。
 * 算法思想:
 *   用 p 从头至尾扫描单链表，pre 指向 *p 结点的前驱。若p所指结点的值为x，则删除，并让p移向下一个结点，否则让pre、p指针同步后移一个结点。
 */















