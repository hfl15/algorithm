/*
	[二叉树的下一个结点]

    [题目]
	给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
	注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

    [解析]
    中序遍历的下一个结点，只有两种情况：
    1. 如果存在右子树，则是右子树中最左边的叶子结点
    2. 否则往父结点的方向回溯，如果当前结点是父结点的右孩子，则说明当前子树已经遍历完，继续往回找；
       如果当前结点是父结点的左孩子，则说明左子树已遍历完，返回根结点，即父结点。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* parent;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(pNode == NULL)
            return NULL;

        if(pNode->right){
            return LeftMost(pNode->right);
        }else if(pNode->parent){
            return GetParentWithLeftChild(pNode);
        }else{
            return NULL;
        }
    }

    TreeLinkNode* LeftMost(TreeLinkNode* pNode){
        if(pNode == NULL)
            return NULL;
        while(pNode->left){
            pNode = pNode->left;
        }
        return pNode;
    }

    TreeLinkNode* GetParentWithLeftChild(TreeLinkNode* pNode){
        TreeLinkNode* pParent = pNode->parent;
        while(pParent && pParent->left != pNode){
            pNode = pParent;
            pParent = pParent->parent;
        }
        return pParent;
    }
};

int main()
{
    return 0;
}