/*
    [链表中环的入口结点]

    [题目]
	一个链表中包含环，请找出该链表的环的入口结点。

    [解析]

    1. 一个快指针和一个慢指针，在环中，快指针肯定会反向追上慢指针。（假想两个人在操场上跑步，快的人的速度时慢的人的两倍，必将会与慢的人几次相遇）
    2. 两个指针重合的地方必定在环内，这个时候可以数一数环内有几个结点。只需要动其中一个指针遍历一遍又回到重合位置即可统计出环内结点数，假设为 k 。
    3. 这时快慢指针 pSlow 和 pFast 从链表头开始。pFast 先比 pSlow 走 k 步，
       如果给结点编号，从数值上看有，pSlow+k = pFast，然后两个指针同步没次向前移动一步，
       那么当 pSlow 到达环的入口节点时，pFast = pSlow+k，因为环只有 k 个节点，pFast 
       相当于又回到了环的开始即入口节点，两指针重合。
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