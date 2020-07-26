/*
	[反转链表]
	题目描述：输入一个链表，反转链表后，输出新链表的表头。
*/
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* ReverseList(ListNode *pHead){
		if(pHead == NULL)
			return pHead;

		ListNode *pPrev = NULL;
		ListNode *pCur = pHead;
		ListNode *pNext = NULL;
		while(pCur){
			pNext = pCur->next;
			pCur->next = pPrev;
			pPrev = pCur;
			pCur = pNext;
		}
		pHead->next = NULL;
		ListNode *pHeadReversed = pPrev;
		
		return pHeadReversed;
	}
};

int main()
{
	return 0;
}
