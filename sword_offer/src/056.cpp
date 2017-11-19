/*
	[合并两个排序链表]

	输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

class Solution{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode* pHead = new ListNode(0);
        ListNode* prev = pHead;

        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                prev->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                prev->next = pHead2;
                pHead2 = pHead2->next;
            }
            prev = prev->next;
        }

        if(pHead1)
            prev->next = pHead1;
        if(pHead2)
            prev->next = pHead2;

        prev = pHead;
        pHead = pHead->next;
        delete prev;

        return pHead;
    }
};

int main()
{
	return 0;
}