/*
	[连续子数组最大和]
    
    [题目]
	HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
	今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
	但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
	例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
	你会不会被他忽悠住？(子向量的长度至少是1)

    [解析]
    动态规划的思想。假设 dp[i] 表示 array[0,..,i] 的最大和。
    那么 dp[i] = max(dp[i-1]+ dp[i], array[i])。
    因为每一次计算只与前一个状态有关，进一步可以减小空间。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        int curSum = 0;
        int maxSum = numeric_limits<int>::min();

        for(int n : array){
            if(curSum < 0){
                curSum = n;
            }else{
                curSum += n;
            }

            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

int main()
{
    return 0;
}