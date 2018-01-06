/*

	[包含min函数的栈]

    [题目]
	定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

    [解析]
    - 解法 1: 
        两个栈，一个存储值(stackVal)，一个存储当前的最小值(stackMin)，一一对应。
        空间复杂度，如果有 n 个 int 类型的数，则 O(2\*n\*sizeof(int))
        - push 一个值 val 时，if(val < stackMin.top): stackMin.push(val) else : stackMin.push(stackMin.top())
        - pop, stackVal.pop, stackMin.pop()
    - 解法 2 （见下面的第一个代码段）：
        值使用 vector 存储以便于获取下标，minIndexs 存储最小值对应的下标（与 1 不同的是，相同的最小值不需要重复入栈）。
        最坏的空间复杂度还是：O(2\*n\*sizeof(int))。
    - 解法 3 (见下面的第二个代码段)：
        - stackVal 存储 x = value - minVal，即当前值和最小值的差值
        - 注意类型：long，因为当 minVal 为 int 范围内最小的数时，只要 value>0， x 就会超过 int 可以表示的范围。
        - 空间复杂度，由于堆栈使用的是 long 型的，sizeof(long) = 2*sizeof(int)，因此空间复杂度较第二种情况并没有减小。

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


