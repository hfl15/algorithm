/*
    [链表中环的入口结点]

    [题目]
	一个链表中包含环，请找出该链表的环的入口结点。

    [解析]

    1. 一个快指针和一个慢指针，在环中，快指针肯定会反向追上慢指针。（假想两个人在操场上跑步，快的人的速度是慢的人的两倍，必将会与慢的人几次相遇）
    2. 两个指针重合的地方必定在环内，这个时候可以数一数环内有几个结点。只需要动其中一个指针遍历一遍又回到重合位置即可统计出环内结点数，假设为 k 。
       又设链表总共有 n 个节点，此时不在环内的节点有 n-k 个。
    3. 这时快慢指针 pSlow 和 pFast 从链表头开始。pFast 先比 pSlow 走 k 步，如果给结点编号，从数值上看有，pSlow+k = pFast。
       此后 pFlast 和 pSlow 同步向前逐步移动，两者相遇的点即为入口。此时 pSlow 走过了 n-k 步，指向入口结点；pFast 走过 k+(n-k)= n，刚好把所有节点都遍历一遍回到入口节点。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(pHead == NULL)
            return NULL;

        // count the number notes in loop
        ListNode* pSlow = pHead;
        ListNode* pFast = pHead->next; // pFast will purse the pSlow
        while(pFast && pFast->next){
            if(pSlow == pFast)
                break;
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        if(pFast == NULL || pFast->next == NULL) // no loop
            return NULL;

        int k = 1;
        pSlow = pSlow->next;
        while(pSlow != pFast){
            pSlow = pSlow->next;
            k++;
        }

        pSlow = pHead;
        pFast = pHead;
        for(int i=2; i<=k+1; i++){
            pFast = pFast->next;
        }

        while(pSlow != pFast){
            pSlow = pSlow->next;
            pFast = pFast->next;
        }

        return pFast;
    }
};

int main()
{
    return 0;
}
