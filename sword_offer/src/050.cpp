/*
	[不用加减乘除法做加法]

	写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
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