/*
	[跳台阶]

	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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
