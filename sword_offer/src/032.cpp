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