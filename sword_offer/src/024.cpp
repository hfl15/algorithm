/*
	[二叉搜索树的第 k 个结点]
    
    [题目]
	给定一颗二叉搜索树，请找出其中的第k小的结点，即将二叉树中所有元素从小到大排序的第 k 个结点。

    [解析]
    按中序遍历二叉搜索树就可以获得一个非递减的序列，此时第 k 个就为答案。
    实际上我们只需要按中序遍历访问一遍各个结点，遇到第 k 个结点时返回即可。
    实践复杂度为O(n) , n 为树的结点个数。
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