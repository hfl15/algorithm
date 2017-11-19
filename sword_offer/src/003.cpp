/*
    [链表中环的入口结点]
	一个链表中包含环，请找出该链表的环的入口结点。
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