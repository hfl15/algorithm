/*
	[扑克牌顺子]
    
    [题目]
	一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)。
	随机从中抽出了5张牌, 看看能不能抽到顺子,其中大小王可以变成任意数字。
	A看作1,J为11,Q为12,K为13。为了方便起见,你可以认为大小王是0。

    [解析]
    注意：当数组存在重复数字的时候不合理。假设数字满足扑克牌的要求，没有进行检查。
    核心思想：统计 0 的个数，如果将数组有序排序，那么相邻数字差为 1，若大于 1 则累计 gab，
            当 gab 能被 0 的个数，即王的个数填充时，则可构成顺子。
    思路 1: 对数组进行升序排序，然后依次进行检查。（如下代码）。因为数组只有 5 个元素，排序的时间可以看作是常数。
    思路 2: 因为数字在 [0,13] 之间，可以使用一个大小为 14 的hash数组统计没个数字出现的次数，
           当有任何一个数字的出现的次数超过 1 次，则无法构成顺子。从左到右遍历 hash 数组，即可统计 gab。
           （代码容易实现，此处不给出）
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool IsContinuous( vector<int> numbers ){
        if(numbers.size() != 5)
            return false;

        // the value of each number in numbers is range from 0 to 13.
        // 0 indicate joker, so the number of zero is less and equal to 2.
        // the number of each number of 1 to 13 are less than and equal to 4.

        sort(numbers.begin(), numbers.end());
        int countZero = 0;
        for(; countZero<numbers.size(); countZero++){
            if(numbers[countZero] > 0){
                break;
            }
        }

        int gab = 0;
        for(int i=countZero+1; i<numbers.size(); i++){
            if(numbers[i] == numbers[i-1]) // there exist duplicate 
                return false;
            gab += numbers[i] - numbers[i-1] - 1;
        }

        return gab <= countZero;
    }
};

int main()
{
    return 0;
}