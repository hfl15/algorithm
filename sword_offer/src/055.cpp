/*
	[树的子结构]
    
    [题目]
	输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

    [解析]
    假设 pRoot1 的结点数为 m， pRoot2 的结点数为 n
    方法1: 使用二叉树的遍历方法（如下给出的代码），时间复杂度 O(m*n)
    方法2: 将两棵树进行序列化，可以将树转化为字符串，就编程了字符串的匹配问题，
          判断字符串 str2 是否包含在字符串 str1 中，使用 KMP 算法，最优可以时间复杂度为 O(m+n)

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