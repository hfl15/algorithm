/*
	[序列化二叉树]

    [题目]
	请实现两个函数，分别用来序列化和反序列化二叉树。

    [解析]
    代码实现能力，bug free。
    二叉树的序列化和反序列化，实际上就是要以一种输入和输出统一的二叉树遍历方式进行中间参数的传递。
    常用的二叉树便利方式有：中序，前序，后序和层次遍历。

    其中前序遍历最符合人们的习惯，并且在反序列化过程中，如果字符是以序列的形式到来的，
    我们不需要知道整颗树的完整结构就可以进行树的构建。从这个角度考虑，使用前序遍历进行组织是较为理想的。

    几个细节：
        1. 序列化过程如何表示空结点。
        2. 序列化过程如何将结点的元素隔开。

    我们值需要使用二叉树中不会使用到的特殊字符对相应的特殊情况进行标记即可。

    实现的细节：
        1. 指针的移动。这里的实现使用引用类型是为了递归函数使用同一个全局参数。
        2. 没有完美的代码，只有符合需求的代码。反序列化过程我们假设输入是合法的，获取数值时没有进行溢出等特殊情况的检查。

    总的来说还是应该多动手实践。
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