/*
	[调整数组的顺序使奇数位于偶数的前面]
        
    [题目]
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
	所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

    [解析]
    注意题目的意思，划分之后要求：保证奇数和奇数，偶数和偶数之间的相对位置不变。（因此不能使用快排的 partition 思想，这是不稳定的）
    方法：
        冒泡排序的思想：每次迭代将一个偶数下沉到恰当的位置（注意：只要遇到偶数在前奇数在后的情况才需要交换）
        空间换时间：需要一个额外的数据，直接将数字移到恰当的位置。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void reOrderArray(vector<int> &array){
        //bubbling(array);
        assisSpace(array);
    }

    // time-O(n^2), spcae-O(1)
    void bubbling(vector<int>& array){
        // move one of even number to the end in each iteration
        for(int i=0; i<array.size(); i++){
            for(int j=0; j<(array.size()-i-1); j++){
                if(isEven(array[j]) && !isEven(array[j+1])){
                    swap(array[j], array[j+1]);
                }
            }
        }
    }

    // time-O(n), space-O(n)
    void assisSpace(vector<int>& array){
        int countOdd = 0;
        for(int n : array){
            if(!isEven(n))
                countOdd++;
        }

        vector<int> temp(array.size());
        int iOdd = 0;
        int iEven = countOdd;
        for(int i=0; i<array.size(); i++){
            if(isEven(array[i])){
                temp[iEven++] = array[i];
            }else{
                temp[iOdd++] = array[i];
            }
        }

        array.assign(temp.begin(), temp.end());
    }

    static bool isEven(int n){
        return (n & 1) == 0;
    }
};

int main()
{
    return 0;
}