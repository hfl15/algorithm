/*
	[对称的二叉树]
    
    [题目]
	请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

    [解析]
    可以做图抽象便于理解。注意边界条件。

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
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }

    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == NULL && pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return isSymmetrical(pRoot1->left, pRoot2->right) 
            && isSymmetrical(pRoot1->right, pRoot2->left);
    }
};

int main()
{
    return 0;
}