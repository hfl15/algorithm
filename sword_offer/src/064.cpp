/*
	[包含min函数的栈]

	定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

class Solution{
public:
    void push(int value){
        values.push_back(value);
        if(minIndexs.empty() || value < values[minIndexs.top()]){
            minIndexs.push(values.size()-1);
        }
    }

    void pop(){
        if(values.empty())
            return;

        int val = values.back();
        if(values.size()-1 == minIndexs.top())
            minIndexs.pop();
        values.pop_back();
    }

    int top(){
        return values.back(); // Calling this function on an empty container causes undefined behavior.
    }

    int min(){
        
        //assert( !minIndexs.empty() );
        return values[minIndexs.top()];
    }

private:
    vector<int> values;
    stack<int> minIndexs;
};

class Solution2{
public:
    void push(int value){
        if(stackVal.empty()) // 0 will be push into stackVal
            minVal = value;

        int x = value - minVal;
        if(x < 0){
            // val < minVal, update the minVal
            minVal = value;
        }

        stackVal.push(x); 
    }

    void pop(){
        if(stackVal.empty())
            return;

        int val = stackVal.top();
        if(val <= 0){
            // update min value
            // in this case
            // minValNew - minValOld = x, if x < 0 then minValNew < minValOld, 
            // so the minValNew will become the new minVal ==> minVal = minValNew
            // minValOld = minVal - x
            minVal = minVal - val;
        }

        stackVal.pop();
    }

    int top(){
        // assert stackVal is not empty
        return stackVal.top() + minVal;
    }

    int min(){
        return minVal;
    }
private:
    long minVal;
    stack<long> stackVal;
};


int main()
{
    return 0;
}


