/*
	[跳台阶]
    [题目]
	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

    [解析]
    与斐波那契数列的求解过程类似。典型的动态规划问题。对于第 n 级台阶，
    我们可以从第 n-1 级台阶一步到达，也可以从第 n-2 级台阶一步达到，
    则有递归式：f[n] = f[n-1] + f[n-2]，
    初始状态 f[1] = 1, f[2] = 2。
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int jumpFloor(int number){
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;

        // f[n] = f[n-1] + f[n-2]
        int f1 = 1;
        int f2 = 2;
        for(int i=3; i<=number; i++){
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
