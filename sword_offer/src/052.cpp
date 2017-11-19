/*
	[复杂链表的复制]

	输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
	返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
public:
    RandomListNode* Clone(RandomListNode* pHead){
        //return CloneMap(pHead);
        return CloneTrick(pHead);
    }

    // time-O(n), space - O(n*2*size(RandomListNode))
    RandomListNode* CloneMap(RandomListNode* pHead){
        if(pHead == NULL)
            return NULL;

        unordered_map<RandomListNode*, RandomListNode*> hash; // <node_origin, node_new>
        
        // copy node
        RandomListNode* pHeadClone = new RandomListNode(pHead->label);
        hash[pHead] = pHeadClone;
        RandomListNode* p = pHead->next;
        RandomListNode* prevClone = pHeadClone;
        while(p){
            prevClone->next = new RandomListNode(p->label);
            prevClone = prevClone->next;
            hash[p] = prevClone;
            p = p->next;
        }

        // copy random
        p = pHead;
        while(p){
            if(p->random != NULL){
                hash[p]->random = hash[p->random];
            }
            p = p->next;
        }

        return pHeadClone;
    }

    // time-O(2*n), space-O(1)
    RandomListNode* CloneTrick(RandomListNode* pHead){
        if(pHead == NULL)
            return NULL;

        // copy new node for each node in the original node of pHead
        RandomListNode *p = pHead;
        while(p){
            RandomListNode *pNew = new RandomListNode(p->label);
            pNew->next = p->next;
            p->next = pNew;
            p = pNew->next;
        }

        // copy random
        p = pHead;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }


        // split list
        RandomListNode* pHeadClone = pHead->next;
        RandomListNode* prevClone = pHeadClone;
        RandomListNode* prevOrigin = pHead;
        int flag = 1; // 1 : orignal node; 0: new node
        p = pHeadClone->next;
        while(p){
            if(flag){ // origin
                prevOrigin->next = p;
                prevOrigin = prevOrigin->next;
            }else{
                prevClone->next = p;
                prevClone = prevClone->next;
            }
            flag = 1 - flag;
            p = p->next;
        }

        prevClone->next = NULL;
        prevOrigin->next = NULL;

        return pHeadClone;
    }
};

int main()
{
    return 0;
}