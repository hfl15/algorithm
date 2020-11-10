/*
	[两个链表的第一个公共结点]
    
    [题目]
	输入两个链表，找出它们的第一个公共结点。

    [解析]
    链表和树的题最好是作图举例子。核心思路：
        1. 确定较长的链表比较短的链表多的结点数 k；
        2. 在长的链表上提前走 k 步；
        3. 同时移动两个链表上的指针，返回第一个相同的节点。
    其中：确定多处的结点数，有小 trick，参看代码。
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
	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
		if (headA == NULL || headB == NULL)
			return NULL;

		ListNode *pa, *pb;

		pa = headA;
		pb = headB;
		while(pa && pb){
			pa = pa->next;
			pb = pb->next;
		}
		if(pa == NULL) // headA is shorter
			pa = headB;
		if(pb == NULL) // headB is shorter
			pb = headA;

		while(pa && pb){
			pa = pa->next;
			pb = pb->next;
		}
		if(pa == NULL)
			pa = headB;
		if(pb == NULL)
			pb = headA;

		while(pa && pb){
			if(pa == pb)
				return pa;
			pa = pa->next;
			pb = pb->next;
		}

		return NULL;
	}
};

int main()
{
    return 0;
}
