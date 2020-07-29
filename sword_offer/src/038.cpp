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
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		//return MoreThanHalfNumWithMap(numbers);
		//return MoreThanHalfNumWithPartition(numbers);
		return MoreThanHalfNumWithTrick(numbers);
    }

	int MoreThanHalfNumWithMap(vector<int>& numbers){
		unordered_map<int, int> hash;
		unordered_map<int, int>::iterator it;

		for(int n : numbers){
			it = hash.find(n);
			if(it == hash.end()){
				//hash.insert(pair<int, int>(n, 1));
				hash[n] = 1;
			}else{
				hash[n]++;
				//it->second++;
			}
		}

		int half_len = numbers.size() / 2;
		for(it = hash.begin(); it!=hash.end(); it++){
			if(it->second > half_len)
				return it->first;
		}

		return 0;
	}

	int MoreThanHalfNumWithPartition(vector<int>& numbers){
		if(numbers.size() == 0)
			return 0;

		int middle = numbers.size() >> 1;
		int left = 0, right = numbers.size()-1; 
		int index = Partition(numbers, left, right);
		while(index != middle){
			if(index < middle){
				left = index+1;
				index = Partition(numbers, left, right);
			}else{
				right = index - 1;
				index = Partition(numbers, left, right);
			}
		}

		int ans = numbers[index];
		int count = 0;
		for(int i=0; i<numbers.size(); i++){
			if(numbers[i] == ans)
				count++;
		}

		return count > middle ? ans : 0;
	}
	
	int Partition(vector<int>& numbers, int left, int right){
		int ileft = left+1, iright = right;
		while(ileft < iright){
			while(ileft<iright && numbers[ileft] <= numbers[left])
				ileft++;
			while(ileft<iright && numbers[iright] > numbers[left])
				iright--;
			if(ileft < iright){
				swap(numbers[ileft], numbers[iright]);
				ileft++;
				iright--;
			}
		}
		swap(numbers[left], numbers[ileft-1]);
		return ileft-1;
	}

	int MoreThanHalfNumWithTrick(vector<int>& number){
		if(number.size() == 0)
			return 0;

		int ans = number[0];
		int count = 1;
		for(int i=1; i<number.size(); i++){
			if(number[i] == ans)
				count++;
			else{
				if(count > 0)
					count--;
				else{
					ans = number[i];
					count = 1;
				}
			}
		}

		count = 0;
		for(int i=0; i<number.size(); i++){
			if(number[i] == ans)
				count++;
		}
		
		return count > (number.size() >> 1) ? ans : 0;
	}
};

int main()
{ // 9 1 2 3 2 2 2 5 4 2
	int n;
	cin >> n;
	vector<int> numbers(n);
	for(int i=0; i<n; i++)
		cin >> numbers[i];

	Solution s = Solution();
	int ans = s.MoreThanHalfNum_Solution(numbers);
	cout << ans << endl;

	return 0;
}
