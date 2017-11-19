/*
	[用两个栈实现队列]

	用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/


class Solution{
public:
    void push(int node) {
        stackPush.push(node);
    }

    int pop() {
        if(stackPop.empty()){
            while(!stackPush.empty()){
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }

        if(stackPop.empty()){
            return -1;
        }else{
            int val = stackPop.top();
            stackPop.pop();
            return val;
        }
    }

private:
    stack<int> stackPush;
    stack<int> stackPop;
};