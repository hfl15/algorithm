/*
	[从尾到头打印链表]

    [题目]
	输入一个链表，从尾到头打印链表每个节点的值。

    [解析]
    2 个思考方向：
        1. 自然的递归，注意递归的出口 （隐含有调用栈）
        2. 使用栈来模拟递归过程
    注意：
        1. 递归过程需要层层深入，会使用到递归调用栈，当链表很长时，有可能会出现堆栈溢出。因此第二个使用栈结构较优。
        2. 指针！！！
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        // vector<int> ans;
        // printListFromTailToHeadRecursive(head, ans);
        // return ans;

        return printListFromTailToHeadIterate(head);
    }

    vector<int> printListFromTailToHeadIterate(ListNode* head){
        vector<int> ans;
        stack<int> sNotes;
        ListNode* p = head;
        while(p){
            sNotes.push(p->val);
            p = p->next;
        }

        while(!sNotes.empty()){
            ans.push_back(sNotes.top());
            sNotes.pop();
        }

        return ans;
    }

    void printListFromTailToHeadRecursive(ListNode* head, vector<int>& ans){
        if(head == NULL)
            return;
        printListFromTailToHeadRecursive(head->next, ans);
        ans.push_back(head->val);
    }
};

int main()
{
    return 0;
}