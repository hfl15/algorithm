/*
	[链表中倒数第k个结点]

    [题目]
	输入一个链表，输出该链表中倒数第k个结点。

    [解析]
    - 注意输入的合法性检查
    - 注意边界条件的检查
    - trick，快慢指针
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
        if(pListHead == NULL)
            return pListHead;
        if(k <= 0)
            return NULL;

        // point to the first note
        ListNode* pSlow = pListHead;
        ListNode* pFast = pListHead;
        
        // move the pFast by k-1 step
        int i=1;
        for(; i<k && pFast != NULL; i++){
            pFast = pFast->next;
        }

        if(pFast == NULL)
            return NULL;

        // pFast point to the k-th note
        // pSlow point to the 1-th note

        while(pFast->next){
            pSlow = pSlow->next;
            pFast = pFast->next;
        }

        return pSlow;
    }
};

int main()
{
    return 0;
}