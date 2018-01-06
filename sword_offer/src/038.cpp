/*

	[数组中出现次数超过一半的数字]
    
    [题目]
	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
	由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

    [解析]
    方法0: 
        双重循环统计每个数的次数，最笨的方法，时间复杂度-O(n^2)
    方法1: 
        使用 hash 表对数组中的每个数进行统计，由此找出次数超过一半的数；时间复杂度 O(n)，空间复杂度-O(n)
    方法2: 
        实际上超过数组长度一半的数，如果这个数存在，当数组有序时，第 n/2，即中位数一定是答案。
        这就可以将问题转换成 top k 的问题，k = n／2，最好的情况下以 partition 的思想可以在平均时间复杂度 O(n) 的情况下完成。
    方法3:
        如下面代码实现。使用trick，我们成对的删除数字，最后剩下的数字肯定是超过半数的数字。
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