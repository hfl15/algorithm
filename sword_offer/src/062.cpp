/*
	[从上往下打印出二叉树的每个节点，同层节点从左至右打印。]
    
    [题目]
	从上往下打印出二叉树的每个节点，同层节点从左至右打印。

    [解析]
    熟悉队列的应用。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root){
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* p = Q.front();
            Q.pop();
            ans.push_back(p->val);
            if(p->left)
                Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }

        return ans;
    }
};

int main()
{
    return 0;
}