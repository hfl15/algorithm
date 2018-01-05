/*
	[按之字形顺序打印二叉树]
    
    [题目]
	请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
	第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

    [解析]
    技巧：flag 的使用，借助栈的结构。分析题目时候可以先举一个简单的例子，发现规律。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), right(NULL) {}
};

class Solution{
public:
    vector<vector<int> > Print(TreeNode* pRoot){
        vector<vector<int> > ans;
        if(pRoot == NULL)
            return ans;

        int flag = 0; // flag=0: from left to right; flag=1: from right to left
        vector<stack<TreeNode*> > vecStack(2);
        vecStack[flag].push(pRoot);
        while(!vecStack[flag].empty()){
            vector<int> temp;
            while(!vecStack[flag].empty()){
                TreeNode* pCur = vecStack[flag].top();
                vecStack[flag].pop();
                temp.push_back(pCur->val);
                if(flag == 0){
                    // from left to right
                    if(pCur->left)
                        vecStack[1-flag].push(pCur->left);
                    if(pCur->right)
                        vecStack[1-flag].push(pCur->right);
                }else{
                    // from right to left
                    if(pCur->right)
                        vecStack[1-flag].push(pCur->right);
                    if(pCur->left)
                        vecStack[1-flag].push(pCur->left);
                }
            }
            ans.push_back(temp);
            flag = 1 - flag;
        }

        return ans;
    }
};

int main()
{
    return 0;
}