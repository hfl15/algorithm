/*
	[和为S的两个数]
    
    [题目]
	输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
	如果有多对数字的和等于S，输出两个数的乘积最小的。
	输出描述：
	对应每个测试案例，输出两个数，小的先输出。

    [解析]
    注意题目的条件：有序数组
    对于此题的条件，我们可以将 有序 的条件充分利用起来，是用双向指针解决
    扩展，对于一般的无序数组：
    是用 hash 表减小查找的复杂度，空间换时间，时间复杂度为 O(n)
    可以先将数组排序然后是用双向指针求解，时间复杂度依赖于排序算法，因此最好的情况为 O(nlog(n))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum){
        //return FindNumbersWithSumHash(array, sum);
        return FindNumbersWithSumSortedArray(array, sum);
    }

    // time-O(n), space-O(1)
    // Note: the array must be sorted array.
    vector<int> FindNumbersWithSumSortedArray(vector<int> array, int sum){

        int left = 0, right = array.size()-1;
        long long minimum = numeric_limits<int>::max();
        int cond1, cond2;
        while(left < right){
            int curSum = array[left] + array[right];
            if(curSum > sum)
                right--;
            if(curSum < sum)
                left++;
            if(curSum == sum){
                long long mul = array[left] * array[right];
                if(mul < minimum){
                    minimum = mul;
                    cond1 = array[left];
                    cond2 = array[right];
                }
                left++; // note: escape the duplication to avoid the infinite loop
            }
        }

        if(minimum == numeric_limits<int>::max()){
            return vector<int>();
        }else{
            vector<int> ans(2);
            ans[0] = cond1;
            ans[1] = cond2;
            return ans;
        }
    }

    // time-O(n) , space-O(n)
    vector<int> FindNumbersWithSumHash(vector<int> array, int sum){
        unordered_set<int> setNums;
        long long minimum = numeric_limits<long long>::max();
        int cond1, cond2;
        for(int n : array){
            int another = sum - n;
            if(setNums.find(another) != setNums.end()){
                if(another * n < minimum){
                    cond1 = n;
                    cond2 = another;
                    minimum = another*n;
                }
            }
            setNums.insert(n);
        }

        if(minimum == numeric_limits<long long>::max()){
            return vector<int>();
        }else{
            if(cond2 < cond1)
                swap(cond1, cond2);
            vector<int> ans(2);
            ans[0] = cond1;
            ans[1] = cond2;
            return ans;
        }
        
    }
};

int main()
{
    return 0;
}