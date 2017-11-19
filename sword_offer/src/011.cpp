/*
	[平衡二叉树]

	输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    bool IsBalanced_Solution(TreeNode* pRoot){
        int depth;
        return IsBalanced_Solution(pRoot, depth);
    }

    bool IsBalanced_Solution(TreeNode* pRoot, int& depth){
        if(pRoot == NULL){
            depth = 0;
            return true;
        }
        int depthLeft;
        int depthRight;
        bool ansLeft = IsBalanced_Solution(pRoot->left, depthLeft);
        if(ansLeft == false)
            return false;
        bool ansRight = IsBalanced_Solution(pRoot->right, depthRight);
        if(ansRight == false)
            return false;

        depth = max(depthLeft, depthRight) + 1;

        return abs(depthLeft-depthRight)<=1;

    }
};

int main()
{
    return 0;
}