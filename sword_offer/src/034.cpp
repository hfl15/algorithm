/*
	[最小k个数]
    
    [题目]
	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

    [解析]
    方法0: 直接排序然后返回前k个，最好的时间复杂度为 O(nlog(n))
    方法1: 快排的变种，时间复杂度 O(n)，缺点：修改输入；原址，需要把所有数都 load 到内存中
    方法2: 利用最大堆作为辅助，时间复杂度 O(n*lg(k))，适用于处理数据量很大的情况。
    方法3：使用红黑树，其查找可以控制在 lg(k)，c++ 中 multiset 的实现就是基于红黑树的。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // greater, less
#include <set>

using namespace std;

typedef multiset<int, greater<int> > iniSet;
typedef multiset<int, greater<int> >::iterator setIter;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		//return GetLeastNumbers_Partition(input, k);
		//return GetLeastNumbers_MaxHeap(input, k);
		return GetLeastNumbers_Multiset(input, k);
    }

	vector<int> GetLeastNumbers_Partition(vector<int> &input, int k){
		if(input.size() < k || input.empty())
			return vector<int>();

		int left = 0, right = input.size()-1;
		int index = Partition(input, left, right);
		while(index != k-1){
			if(index < k-1){
				left = index + 1;
			}else{
				right = index - 1;
			}
			index = Partition(input, left, right);
		}

		vector<int> ans(k);
		for(int i=0; i<k; i++)
			ans[i] = input[i];
		return ans;
	}

	int Partition(vector<int> &intput, int left, int right){
		if(intput.size() == 0 || left > right)
			return -1;
		if(left == right)
			return left;

		int ileft = left+1;
		int iright = right;
		while(ileft < iright){
			while(ileft < iright && intput[ileft] < intput[left])
				ileft++;
			while(ileft < iright && intput[iright] >= intput[left])
				iright--;
			if(ileft < iright){
				swap(intput[ileft], intput[iright]);
				ileft++;
				iright--;
			}
		}
		swap(intput[left], intput[ileft-1]);
		return ileft-1;
	}

	vector<int> GetLeastNumbers_MaxHeap(vector<int> &input, int k){ // 我本地测试通过，但提交到牛客网时报段错，通过率 0.00%。
		if(input.size() < k || input.empty())
			return vector<int>();
		
		vector<int> ans(input.begin(), input.begin()+k);
		make_heap(ans.begin(), ans.end(), comp); // max heap
		for(int i=k; i<input.size(); i++){
			if(input[i] < ans.front()){
				pop_heap(ans.begin(), ans.end(), comp);
				ans[k-1] = input[i];
				push_heap(ans.begin(), ans.end(), comp);
			}
		}

		return ans;
	}
	static bool comp(int a, int b){
		return a<b;
	}

	vector<int> GetLeastNumbers_Multiset(vector<int> input, int k){
		if(input.size() < k || k < 1 || input.empty())
			return vector<int>();

		iniSet ans;
		for(int i=0; i<input.size(); i++){
			if(ans.size() < k)
				ans.insert(input[i]);
			else{
				setIter itGreatest = ans.begin();
				if(input[i] < *itGreatest){
					ans.erase(itGreatest);
					ans.insert(input[i]);
				}
			}
		}

		vector<int> ansVec(k);
		setIter it = ans.begin();
		int i=0;
		for( ; it != ans.end(); it++, i++){
			ansVec[i] = *it;
		}
		
		return ansVec;
	}
};

void printVector(vector<int>& vec){
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	// 8 4 5 1 6 2 7 3 8 4
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i=0; i<n; i++)
		cin >> input[i];
	int k;
	cin >> k;
	cout << "The input array is: " << endl;
	printVector(input);
	cout << "k = " << k << endl;

	Solution s = Solution();
	vector<int> ans = s.GetLeastNumbers_Solution(input, k);
	cout << "The answer is: " << endl;
	printVector(ans);

	return 0;
}
