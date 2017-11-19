/*
	[两个链表的第一个公共结点]

	输入两个链表，找出它们的第一个公共结点。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;

        ListNode *p1, *p2;
        p1 = pHead1;
        p2 = pHead2;

        while(p1->next && p2->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL)
            p1 = pHead2;
        if(p2->next == NULL)
            p2 = pHead1;

        while(p1->next && p2->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL)
            p1 = pHead2;
        if(p2->next == NULL)
            p2 = pHead1;

        while(p1 && p2){
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};

int main()
{
    return 0;
}