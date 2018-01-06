/*
	[数组中的逆序对]

    [题目]
	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007.
	输入描述：题目保证输入的数组中没有的相同的数字
	数据范围：
		对于%50的数据,size<=10^4
		对于%75的数据,size<=10^5
		对于%100的数据,size<=2*10^5

    [解析]
    方法1： 
        使用二重转换统计每个数的逆序对，时间复杂度 O(n^2)
    方法2: 
        改进的归并排序，分而治之，时间复杂度 O(n*log(n))，空间复杂度 O(n) （这里不包括递归栈的开销）
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int InversePairs(vector<int> data){
        int ans = 0;
        mergeSort(data, 0, data.size()-1, ans);
        return ans;
    }

    // time-O(n*log(n))
    void mergeSort(vector<int>& data, int left, int right, int &ans){
        int len = right - left + 1;
        if(len <= 1)
            return;

        int mid = (right+left)/2;
        // sort
        mergeSort(data, left, mid, ans);
        mergeSort(data, mid+1, right, ans);

        // merge
        vector<int> temp(len);
        int i=0, i1 = left, i2 = mid+1;
        while(i1 <= mid && i2 <= right){
            if(data[i1] <= data[i2]){
                temp[i] = data[i1++];
            }else{
                // reverse pair
                ans = (ans + (mid-i1+1)%MODE)%MODE;
                temp[i] = data[i2++];
            }
            i++;
        }

        while(i1 <= mid)
            temp[i++] = data[i1++];
        while(i2 <= right)
            temp[i++] = data[i2++];

        // copy temp to original data
        for(int i=0; i<temp.size(); i++){
            data[left+i] = temp[i];
        }
    }
private:
    static const int MODE = 1000000007;
};

int main()
{
    freopen("in.txt", "r", stdin);
    vector<int> data;
    int cur;
    while(cin>>cur){
        data.push_back(cur);
    }

    cout << Solution().InversePairs(data) << endl;
    fclose(stdin);
    return 0;
}