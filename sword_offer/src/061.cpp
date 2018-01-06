/*
	[二叉搜索树的后序遍历序列]
    
    [题目]
	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
	如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

    [解析]
    理解二叉搜索树的定义。
    注意：
        - 任意两个数互不相同。
        - 代码实现中数组为空的情况要考虑在内。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool VerifySquenceOfBST(vector<int> sequence){
        if(sequence.empty()) // Note: special case
            return false;

        return VerifySquenceOfBSTRecursive(sequence, 0, sequence.size()-1);
    }

    bool VerifySquenceOfBSTRecursive(vector<int> &sequence, int left, int right){
        if(left >= right) // null tree or just have one note
            return true;

        int rootVal = sequence[right];
        int iright = right-1;
        while(iright >= left && sequence[iright] > rootVal)
            iright--;

        // checke left tree, the value should be less than rootVal
        int ileft = iright-1;
        for( ; ileft>=left; ileft--){
            if(sequence[ileft] > rootVal)
                return false;
        }

        return VerifySquenceOfBSTRecursive(sequence, left, iright-1) 
            && VerifySquenceOfBSTRecursive(sequence, iright, right-1);
    }
};

int main()
{
    return 0;
}