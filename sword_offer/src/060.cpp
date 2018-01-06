/*
	[栈的压入、弹出序列]
    
    [题目]
	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
	假设压入栈的所有数字均不相等。
	例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
	（注意：这两个序列的长度是相等的）

    [解析]
    主要考察栈的使用。
    注意题目中给的提示，数字均不相同并且两个序列等长。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV){
        if(pushV.empty() && popV.empty())
            return true;
        if(pushV.empty() || popV.empty())
            return false;

        stack<int> stackVal;
        int ipush = 0, ipop = 0;
        for( ; ipush<pushV.size(); ipush++){
            stackVal.push(pushV[ipush]);
            while(!stackVal.empty() && stackVal.top() == popV[ipop]){
                stackVal.pop();
                ipop++;
            }
        }

        return ipop >= popV.size() && stackVal.empty();
    }
};

int main()
{
    return 0;
}