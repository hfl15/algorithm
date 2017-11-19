/*
	[滑动窗口最大值]

	给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
	例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
	他们的最大值分别为{4,4,6,6,6,5}； 
	针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
	{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
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