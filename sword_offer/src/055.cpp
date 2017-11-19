/*
	[树的子结构]

	输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL || pRoot1 == NULL)
            return false;
        
        if(isSubTree(pRoot1, pRoot2))
            return true;
        else
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == NULL && pRoot2 == NULL)
            return true;
        // pRoot1 != NULL || pRoot2 != NULL
        if(pRoot1 == NULL)
            return false;
        if(pRoot2 == NULL)
            return true;

        if(pRoot1->val != pRoot2->val)
            return false;

        return isSubTree(pRoot1->left, pRoot2->left) && isSubTree(pRoot1->right, pRoot2->right);
    }
};

int main()
{
    return 0;
}