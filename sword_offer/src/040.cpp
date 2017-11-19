/*
	[数组中重复的数字]

	在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
	数组中某些数字是重复的，但不知道有几个数字是重复的。
	也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
	例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
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