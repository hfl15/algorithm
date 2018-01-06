/*
	[最小k个数]
    
    [题目]
	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

    [解析]
    方法0: 直接排序然后返回前k个，最好的时间复杂度为 O(nlog(n))
    方法1: 快排的变种，时间复杂度 O(n)，缺点：原址，需要把所有数都 load 到内存中
    方法2: 利用最大堆作为辅助，时间复杂度 O(n*lg(k))，适用于处理数据量很大的情况。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        vector<int> ans;
        if(k > input.size()){
            return ans;
        }

        // GetLeastNumbersPartition(input, 0, input.size()-1, k);
        // for(int i=0; i<k; i++)
        //  ans.push_back(input[i]);

        // return ans;

        return GetLeastNumbersHeap(input, k);
    }

    // parition, average time complexity - O(n)
    // note: k should less than then size of input
    void GetLeastNumbersPartition(vector<int> &input, int left, int right, int k){
        int pos = partition(input, left, right);
        if(pos == k-1){
            return;
        }else if (pos < k-1){
            GetLeastNumbersPartition(input, pos+1, right, k);
        }else{
            GetLeastNumbersPartition(input, left, pos-1, k);
        }
    }

    int partition(vector<int> &input, int left, int right){
        if(left > right)
            return -1;
        int pos = left-1;
        for(int i=left; i<right; i++){
            if(input[i] <= input[right]){
                swap(input[i], input[++pos]);
            }
        }

        swap(input[right], input[++pos]);
        // input[left, pos] <= input[pos]
        // input[pos+1, right] > input[pos]
        return pos;
    }

    // heap sort, time complexity - O(nlog(k))
    vector<int> GetLeastNumbersHeap(vector<int> &input, int k){
        
        if(k > input.size() || input.empty())
            return vector<int>();

        vector<int> ans(input.begin(), input.begin()+k); // max heap
        make_heap(ans.begin(), ans.end(), comp);

        for(int i=k; i<input.size(); i++){
            if(input[i] < ans.front()){ // the current value less than the maximun of heap
                pop_heap(ans.begin(), ans.end(), comp);
                ans.pop_back();

                ans.push_back(input[i]);
                push_heap(ans.begin(), ans.end(), comp);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }

    static bool comp(int a, int b){
        return a<b;
    }

};

int main()
{
    freopen("in.txt", "r", stdin);
    int k;

    cin >> k;

    vector<int> input;
    int cur;
    while(cin >> cur){
        input.push_back(cur);
    }

    vector<int> ans = Solution().GetLeastNumbers_Solution(input, k);

    for(int n : ans)
        cout << n << " ";
    cout << endl;

    fclose(stdin);
    return 0;
}