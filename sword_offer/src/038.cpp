/*
	[数组中出现次数超过一半的数字]

	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
	由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        // these two case can't be distinguish by return value: 
        // (1) the more than hal number is 0, 
        // (2) the length of numbers is 0, but the return value also is 0.
        // various different case can be taken to address this problem, which will be need to change the function interface.
        int ans = 0;
        int count = 0;

        for(int n : numbers){
            if(n == ans){
                count++;
            }else{
                if(count == 0){
                    ans = n;
                    count = 1;
                }else{
                    count--;
                }
            }
        }

        // check whether there is a correct solution
        count = 0;
        for(int n : numbers){
            if(n == ans)
                count++;
        }


        return count > numbers.size()/2 ? ans : 0;
    }
};

int main()
{
    return 0;
}