/*

	[136. Single Number - easy]
	
	[description]
	Given an array of integers, every element appears twice except for one. Find that single one.
	Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

	[solution]
	solution: https://leetcode.com/problems/single-number/solution/
	1. hash table
	2. math : 2∗(a+b+c)−(a+a+b+b+c)=c
	3. Bit Manipulation: a xor b xor a = b

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution{
public:
	int singleNumber(vector<int>& nums){
		//return singleNumber_hash(nums);
		//return singleNumber_math(nums);
		return singleNumber_bitManipulation(nums);
	}

	// optimal solution 
	// time - O(n)
	// space - O(1)
	// 24 ms
	int singleNumber_bitManipulation(vector<int>& nums){
		int ans = 0;
		for(int n : nums){
			ans ^= n;
		}

		return ans;
	}

	// time - O(n + n + n)
	// space - O(n * sizeof(n)), for set
	// 19 ms
	int singleNumber_math(vector<int>& nums){
		int sumSet = 0, sumAll = 0;

		// calculate sumSet
		unordered_set<int> set;
		for(int n : nums){
			set.insert(n);
		}
		for(int n : set){
			sumSet += n;
		}
		
		// calculate sumAll
		for(int n : nums){
			sumAll += n;
		}

		return 2*sumSet - sumAll;
	}

	// time-O(n + n), space-O(n * 2 * sizeof(int))
	// 21 ms
	int singleNumber_hash(vector<int>& nums){
		unordered_map<int, int> map_count;
		for(int v : nums){
			map_count[v]++;
		}

		for(auto it = map_count.begin(); it != map_count.end(); ++it){
			if(it->second == 1)
				return it->first;
		}
	}
};

int main()
{
	return 0;
}