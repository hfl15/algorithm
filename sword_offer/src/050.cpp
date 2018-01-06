/*
	[不用加减乘除法做加法]
    
    [题目]
	写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

    [解析]
    使用位运算来完成。熟悉基本的位运算并灵活运用是解题的关键。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    int Add(int num1, int num2){
        // add num2 to num1
        while(num2){
            int numAnd = num1 & num2;
            int numXor = num1 ^ num2;

            num1 = numXor;
            num2 = numAnd<<1; // carry
        }

        return num1;
    }
};

int main()
{
    return 0;
}