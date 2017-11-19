/*
	[序列化二叉树]

	请实现两个函数，分别用来序列化和反序列化二叉树。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    char* Serialize(TreeNode *root){
        string str;
        SerializePreorder(root, str);
        char* cstr = new char[str.size()+1]; // the last one is '\0' indicate the end of char string
        strcpy(cstr, str.c_str());

        return cstr;
    }

    void SerializePreorder(TreeNode *root, string &str){
        if(root == NULL){
            str.append("#");
            return;
        }

        str.append(to_string(root->val)+"|"); // | indicate the end of number
        SerializePreorder(root->left, str);
        SerializePreorder(root->right, str);
    }

    TreeNode* Deserialize(char *str) {
        if(str==NULL || *str=='\0')
            return NULL;
        return DeserializePreorRecursive(str);
    }

    TreeNode* DeserializePreorRecursive(char* &str){
        if(str == NULL || *str=='\0'){
            return NULL;
        }
        if(*str=='#'){
            str++;
            return NULL;
        }

        // Note, in this case, we assume the type of value is int so didn't check for overflow.
        // we assume the input str is legal.
        int val = 0;
        while(*str != '\0' && *str != '|'){
            val = val*10 + *str-'0';
            str++;
        }
        if(*str == '|')
            str++;

        TreeNode* pRoot = new TreeNode(val);
        pRoot->left = DeserializePreorRecursive(str);
        pRoot->right = DeserializePreorRecursive(str);

        return pRoot;
    }
};

int main()
{
    return 0;
}