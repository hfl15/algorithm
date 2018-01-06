/*
	[二叉树中和为某一值的路径]
    
    [题目]
	输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
	路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

    [解析]
    递归回溯。
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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber){
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;

        vector<int> curPath;
        int curSum = 0;

        FindPathRecursive(root, curSum, curPath, expectNumber, ans);

        return ans;
    }

    void FindPathRecursive(TreeNode* root, int &curSum, vector<int> &curPath, int expectNumber, vector<vector<int> > &ans){
        if(root == NULL) // which cann't be reach at normal flow
            return;

        curSum += root->val;
        curPath.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            // leaf
            if(curSum == expectNumber)
                ans.push_back(curPath);
        }else{
            if(root->left)
                FindPathRecursive(root->left, curSum, curPath, expectNumber, ans);
            if(root->right)
                FindPathRecursive(root->right, curSum, curPath, expectNumber, ans);
        }

        curSum -= root->val;
        curPath.pop_back();
    }
};

int main()
{
    return 0;
}