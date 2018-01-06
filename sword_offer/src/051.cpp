/*
	[二叉搜索树与双向链表]
    
    [题目]
	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

    [解析]
    采用中序遍历二叉搜索树，可以得到排序的结果。
    注意边界条件。

*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL)
            return NULL;

        TreeNode* prev = NULL;
        ConvertRecursive(pRootOfTree, prev);

        // find head;
        TreeNode* pHead = pRootOfTree;
        while(pHead->left)
            pHead = pHead->left;
        return pHead;
    }

    void ConvertRecursive(TreeNode* pRootOfTree, TreeNode* &prev){
        if(pRootOfTree == NULL)
            return;

        // left
        ConvertRecursive(pRootOfTree->left, prev);
        
        // root
        if(prev != NULL)
            prev->right = pRootOfTree;
        pRootOfTree->left = prev;
        prev = pRootOfTree;

        // right
        ConvertRecursive(pRootOfTree->right, prev);
    }
};

int main()
{
    return 0;
}