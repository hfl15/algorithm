/*
	[丑数]

    [题目]
	把只包含因子2、3和5的数称作丑数（Ugly Number）。
	例如6、8都是丑数，但14不是，因为它包含因子7。 
	习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

    [解析]
    方法一：
        按照丑数的定义去判断每一个数是否为丑数，时间复杂度 O(n*log(n))，n 是最后一个丑数的值，实践复杂度很高。
    方法二：
        基于已求出来的丑数来求剩下的丑数。假设iMul2, iMul3, Mul5, 
        新的丑数只能是原来丑数的 2，3，或 5 倍，我们只需要记住上次更新后最后的因子位置即可。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int GetUglyNumber_Solution(int index) {
        //return GetUglyNumberIntuition(index);
        return GetUglyNumberIterative(index);
    }

    // time O(n)
    int GetUglyNumberIterative(int index){
        if(index < 1)
            return 0;

        vector<int> uglyNums;
        uglyNums.push_back(1);
        int iMul2 = 0, iMul3 = 0, iMul5 = 0;
        for(int i=0; i<index-1; i++){
            int uglyNext = min(uglyNums[iMul2]*2, min(uglyNums[iMul3]*3, uglyNums[iMul5]*5));
            uglyNums.push_back(uglyNext);

            while(uglyNums[iMul2]*2 <= uglyNext)
                iMul2++;
            while(uglyNums[iMul3]*3 <= uglyNext)
                iMul3++;
            while(uglyNums[iMul5]*5 <= uglyNext)
                iMul5++; 
        }

        return uglyNums.back();
    }

    // time exceeding 
    // O(n*log(n)), n maybe very large
    int GetUglyNumberIntuition(int index){
        if(index < 1)
            return 0;

        int number = 1;
        int count = 1;
        while(count < index){
            number++;
            if(isUgly(number))
                count++;
        }

        return number;
    }

    bool isUgly(int number){
        while(number % 2 == 0)
            number = number / 2;
        while(number % 3 == 0)
            number = number / 2;
        while(number % 5 == 0)
            number = number / 5;

        return number == 1;
    }
};

int main()
{
    cout << Solution().GetUglyNumber_Solution(10) << endl;
    return 0;
}