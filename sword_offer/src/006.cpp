/*
	[变态跳台阶]

	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
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