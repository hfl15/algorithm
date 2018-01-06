/*
	[二进制中 1 的个数]
    
    [题目]
	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

    [解析]
    方法1: 
        常规思路（如代码中的 NumberOf1Mask），逐位数 1 的个数，执行 32 次循环 
        （注意，这里使用标志变量，而不是直接对输入变量进行移位，因为如果右移有符号整数，左边补的是符号位，最后进入死循环）
    方法2:
        小trick（如代码中的 NumberOf1Trick），代码中有多少个 1 就执行多少次循环。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int  NumberOf1(int n) {
        //return NumberOf1Mask(n);
        return NumberOf1Trick(n);
    }

    int NumberOf1Trick(int n){
        int ans = 0;
        while(n){
            ans ++;
            n = n & (n-1);
        }

        return ans;
    }

    int NumberOf1Mask(int n){
        int ans = 0;
        unsigned int mask = 1;

        while(mask){
            if(n & mask)
                ans++;
            mask <<= 1;
        }

        return ans;
    }
};

int main()
{
    return 0;
}