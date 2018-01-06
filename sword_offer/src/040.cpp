/*

	[数组中重复的数字]
    
    [题目]
	在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
	数组中某些数字是重复的，但不知道有几个数字是重复的。
	也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
	例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

    [解析]
    方法0:
        双重循环，外层遍历所有的数字 number，内层循环遍历数组并统计 number 出现的次数。出现重复返回即可。
        时间复杂度 O(n^2)
    方法1:
        用空间换时间。使用 hash 表，遍历一次数组即可完成每个数次数的统计。最后再便利一次 hash 表即可得到重复的数字。
        时间复杂度 O(n)，空间复杂度 O(n)。
        对于 c ++ 可以使用
    方法2：
        使用题目的性质进一步优化。
        注意题目：长度为n的数组中，所有的数字都在 0 ～ n-1 的范围内。长度为 n 的数组，则下标从 0 到 n-1。
        对于数组 arry, arry[i] 可以放在下标为 arry[i] 的位置，即数组中的元素值等于其在数组中的下标位置。
        如果这一条件得不到满足，即检查到 arry[i] != i 时，
        我们应该将 arry[i] 放到 arry[arry[i]]，如果 arry[arry[i]] 满足要求，此时其中一对重复的数字被找到，直接返回即可。

        空间复杂度-O(1)；时间复杂度-O(n)：遍历一次数组为每个数找到对应的位置，没个数最多交换 2 次可以回到其原来的位置。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool duplicate(int number[], int length, int* duplication){
        vector<int> numbers;
        for(int i=0; i<length; i++)
            numbers.push_back(number[i]);

        //return duplicateMap(numbers, duplication);
        //return duplicateSet(numbers, duplication);
        return duplicateTrick(numbers, duplication);
    }

    // time-O(n), space-O(2*n)
    bool duplicateMap(vector<int> numbers, int* duplication){
        if(numbers.empty()){
            return false;
        }

        unordered_map<int, int> mapCount;
        for(int n : numbers){
            mapCount[n]++;
            if(mapCount[n] > 1){ // return the firt duplicate number
                *duplication = n;
                return true;
            }
        }

        return false;
    }

    // time-O(n), scpae-O(n)
    bool duplicateSet(vector<int> numbers, int* duplication){
        unordered_set<int> setNumber;
        for(int n : numbers){
            if(setNumber.find(n) != setNumber.end()){ // return the first one duplicate number
                *duplication = n;
                return true;
            }
            setNumber.insert(n);
        }

        return false;
    }

    // time-O(n), spcae-O(1)
    bool duplicateTrick(vector<int> numbers, int* duplication){
        for(int i=0; i<numbers.size(); i++){
            if(i == numbers[i])
                continue;
            do{
                int ireal = numbers[i];
                if(numbers[ireal] == ireal){
                    // return the first duplicate number
                    *duplication = numbers[i];
                    return true;
                }else{
                    swap(numbers[i], numbers[ireal]);
                }
            }while( i != numbers[i]);
        }

        return false;
    }
}; 

int main()
{
    return 0;
}