/*

	[滑动窗口最大值]
    
    [题  目]
	给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
	例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
	他们的最大值分别为{4,4,6,6,6,5}； 
	针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
	{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

    [解析]
    方法 1: 
        以窗口在数组上滑动，没次都重新计算窗口中最大值，那么总的时间复杂度为 O(n*size)，当窗口大小 size 很大时，不可取。
    方法 2：
        以空间换时间，使用一个双端队列，使得每次获取最大值的操作可以在 O(1) 的时间内完成。
        队列的前边存储当前最大值在数组中对应的下标，而其后存储的时有可能成为新的最大值的候选。
        每次循环需要做两件事情：（1）检查当前最大值是否过期，若过期则弹出最前面的元素；
        （2）更新最大值的候选，从后往前检查将对列中小于当前值的所有元素弹出；
        完成以上两个操作以后奖当前元素插入到队列的最后成为候选。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> ans;
        if(num.empty() || size<=0 || num.size() < size)
            return ans;

        deque<int> maxIndexs; // save the index of minimum currently
        // the first window
        for(int i=0; i<min((int)num.size(), (int)size); i++){
            while(!maxIndexs.empty() && num[i] >= num[maxIndexs.back()])
                maxIndexs.pop_back();
            maxIndexs.push_back(i);
        }

        ans.push_back(num[maxIndexs.front()]);
        for(int i=size; i<num.size(); i++){
            if((i-maxIndexs.front()) >= size) // past due
                maxIndexs.pop_front();
            while(!maxIndexs.empty() && num[i] >= num[maxIndexs.back()])
                maxIndexs.pop_back();
            maxIndexs.push_back(i);
            ans.push_back(num[maxIndexs.front()]);
        }

        return ans;
    }
};

int main()
{
    return 0;
}