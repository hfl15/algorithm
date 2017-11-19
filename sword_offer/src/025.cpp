/*
	[数据流的中位数]

	如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
	如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // for less and greater function

using namespace std;

class Solution{
public:
    void Insert(int num){
        if(max_heap.size() < min_heap.size()){
            // insert into max_heap
            if(!max_heap.empty() && max_heap.front() < num){
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                num = min_heap.front();
                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<int>());

        }else{
            // insert into min_heap
            if(!min_heap.empty() && min_heap.front() > num){
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<int>());
                num = max_heap.front();
                pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        }
        
    }

    double GetMedian(){
        if(min_heap.size() == max_heap.size() && !min_heap.empty()){
            return (min_heap.front() + max_heap.front())*1.0 / 2.0;
        }else{ 
            return min_heap.front();
        }
    }

private:
    vector<int> min_heap; // right part, value large than and equal to median
    vector<int> max_heap; // left part, value less than and equal to median
    // insure min_heap.size() >= max_heap.size()
    // and min_heap.size() - max_heap.size() <= 1

};

int main()
{
    return 0;
}