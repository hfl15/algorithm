/*

	[重建二叉树]

    [题目]
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

    [解析]
    要掌握二叉树的几种遍历方式：前，中，后序遍历。递归的构建，还要要注意递归函数的出口，指针的处理。程序假设输出是合法的。
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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
        if(pre.size() != vin.size())
            return NULL;

        return reConstructBinaryTreeRecursive(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }

    TreeNode* reConstructBinaryTreeRecursive(vector<int>& pre, int iPrevLeft, int iPrevRight,
                                             vector<int>& vin, int iVinLeft, int iVinRight){
        if(iPrevLeft > iPrevRight)
            return NULL;

        int valRoot = pre[iPrevLeft];
        
        // find root in vin
        int iVinRoot = iVinLeft;
        for( ; iVinRoot<=iPrevRight; iVinRoot++){
            if(vin[iVinRoot] == valRoot)
                break;
        }

        int lenLeft = iVinRoot - iVinLeft;
        int lenRight = iVinRight - iVinRoot;

        TreeNode* pRoot = new TreeNode(valRoot);
        pRoot->left = reConstructBinaryTreeRecursive(pre, iPrevLeft+1, iPrevLeft+lenLeft, vin, iVinLeft, iVinRoot-1);
        pRoot->right = reConstructBinaryTreeRecursive(pre, iPrevLeft+lenLeft+1, iPrevRight, vin, iVinRoot+1, iVinRight);

        return pRoot;
    }
};

int main()
{
    return 0;
}