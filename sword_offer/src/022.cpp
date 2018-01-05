/*
	[把二叉树打印成多行]
    
    [题目]
	从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
    vector<vector<int> > Print(TreeNode* pRoot){
        vector<vector<int> > ans;
        if(pRoot == NULL)
            return ans;

        queue<TreeNode*> Q;
        Q.push(pRoot);
        while(!Q.empty()){
            vector<int> temp;
            for(int i=0, n=Q.size(); i<n; i++){
                TreeNode *pCur = Q.front();
                Q.pop();
                temp.push_back(pCur->val);
                if(pCur->left)
                    Q.push(pCur->left);
                if(pCur->right)
                    Q.push(pCur->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    return 0;
}