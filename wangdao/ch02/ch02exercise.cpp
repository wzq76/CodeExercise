//
// Created by wzq12 on 2022-06-09.
//

#include "SqList.cpp"
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







