/*
	[二叉搜索树的第 k 个结点]

	给定一颗二叉搜索树，请找出其中的第k小的结点，即将二叉树中所有元素从小到大排序的第 k 个结点。
*/

#include <iostream>
#include <vector>
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
    TreeNode* KthNode(TreeNode* pRoot, int k){
        TreeNode* ans = NULL;
        KthNodeInorder(pRoot, k, ans);
        return ans;
    }

    void KthNodeInorder(TreeNode* pRoot, int &k, TreeNode* &ans){
        if(pRoot == NULL || k<=0)
            return;
        KthNodeInorder(pRoot->left, k, ans);
        k--;
        if(k == 0){
            // the current note is answer
            ans = pRoot;
            return;
        }
        KthNodeInorder(pRoot->right, k, ans);
    }
};

int main()
{
    return 0;
}