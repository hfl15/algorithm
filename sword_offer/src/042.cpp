/*
	[扑克牌顺子]

	一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)。
	随机从中抽出了5张牌, 看看能不能抽到顺子,其中大小王可以变成任意数字。
	A看作1,J为11,Q为12,K为13。为了方便起见,你可以认为大小王是0。
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