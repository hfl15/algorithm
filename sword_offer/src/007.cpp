/*
	[斐波那契数列]
    [题目]
	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39

    [解析]
    首先要知道斐波那契数列的定义；
    典型的递归求解，但存在很多重复子问题
    使用带记忆的自顶向下
    动态规划，根据递归式，第 n 项，只与前两项有关，可只用两个变量来存储进一步减小空间
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n==2)
            return 1;

        // n >= 3
        int f1 = 1;
        int f2 = 1;
        for(int i=3; i<=n; i++){
            int temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }

        return f2;
    }
};

int main()
{
    return 0;
}