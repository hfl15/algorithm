/*
	[二进制中 1 的个数]

	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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