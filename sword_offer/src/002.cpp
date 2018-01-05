/*
    [删除链表中重复的结点]
    
    [题目]
    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
    例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
    
    [解析]
    主要考代码的能力，注意边界条件的考虑，指针判空等。
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
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL)
            return NULL;

        ListNode *pPrev = NULL;
        ListNode *pCur = pHead;
        while(pCur && pCur->next){
            ListNode *pNext = pCur->next;
            if(pNext->val != pCur->val){
                pPrev = pCur;
                pCur = pNext;
            }else{
                // find all duplicate
                while(pNext && pNext->val == pCur->val)
                    pNext = pNext->next;
                if(pPrev == NULL){
                    pHead = pNext;
                }else{
                    pPrev->next = pNext;
                }

                pCur = pNext;
            }
        }

        return pHead;
    }
};

int main()
{
    return 0;
}