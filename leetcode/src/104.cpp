/*
	
	[104. Maximum Depth of Binary Tree - easy]

	[description]
	Given a binary tree, find its maximum depth.
	The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

	[solution]
	1. recursive.
	2. iteration by queue.

*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

	class Solution{
	public:
		int maxDepth(TreeNode *root){
			//return maxDepthRecursive(root);
			return maxDepthIterative(root);
		}

		// 	7 ms
		// time-O(n), n is the number of note in tree.
		// space: recursive stack
		int maxDepthRecursive(TreeNode *root){
			if(NULL == root)
				return 0;

			int depthLeft = maxDepthRecursive(root->left);
			int depthRight = maxDepthRecursive(root->right);

			return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
		}

		// 6 ms
		// time-O(n), n is the number of note in tree
		// space-O(n), queue
		int maxDepthIterative(TreeNode *root){
			if(NULL == root)
				return 0;
			queue<TreeNode*> Q;
			Q.push(root);
			int depth = 0;
			while(!Q.empty()){
				depth++;
				for(int i=0, n=Q.size(); i<n; i++){
					TreeNode* p = Q.front();
					Q.pop();
					if(p->left)
						Q.push(p->left);
					if(p->right)
						Q.push(p->right);
				}
			}

			return depth;
		}
	};

int main()
{
	return 0;
}