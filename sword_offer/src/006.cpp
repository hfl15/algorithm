/*
	[变态跳台阶]

    [题目]
	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
    
    [解析]
    假设 f[n] 表示跳上一个 n 级台阶跳法的总数。
    f[0] = 1
    f[1] = 1
    f[2] = f[1] + f[0] = 2*f[1]
    f[3] = f[2] + f[1] + f[0] = 2*f[2]
    f[4] = f[3] + f[2] + f[1] + f[0] = 2*f[3]
    ...
    f[n] = f[n-1] + f[n-2] + ... + f[0] = 2*f[n-1] // 根据最后一次跳的台阶数将问题分解，从左往右依次为，最后一次跳 1 级台阶，2级台阶，...，n 级别台阶，一般的，如果最后一次跳的台阶数为 i，那么前面还需要跳的台阶数为 n-i，对应的可能组合数为 f[n-i]。

    f[n] = 2*f[n-1] 展开可以得到 f[n] = 2^(n-1)

    由此可得两种解法：

    以动态规划的方式，按照递归式 f[n] = 2*f[n-1] 进行迭代，算法复杂度为 O(n)
    按照 f[n] = 2^(n-1) 进行计算，就变成了求解 2 的 k 次幂的问题，最优的情况，复杂度为 O(lg(n))；2^k = 2^(k/2)*2^(k/2)，二分。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;

        // f[n] = 2*f[n-1]
        int prev = 1;
        for(int i=2; i<=number; i++){
            prev = prev*2;
        }

        return prev;
    }
};

int main()
{
    return 0;
}