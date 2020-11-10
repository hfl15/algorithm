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
	int add(int a, int b){
		while( b != 0){
			unsigned int numAnd = a & b; // C++中负数不支持左移位，因为结果是不定的
			int numXor = a ^ b;

			a = numXor;
			b = numAnd<<1; // carry
		}

		return a;
	}
};


int main()
{
    return 0;
}
