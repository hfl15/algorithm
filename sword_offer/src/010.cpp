/*
	[和为S的连续正数序列]
    
    [题目]
	小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
	但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
	没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
	现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
	输入描述：
	输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。

    [解析]
    双向指针的应用。特别要注意边界条件！！！
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int> > FindContinuousSequence(int sum){
        vector<vector<int> > ans;
        if(sum < 3)
            return ans;
        int islow = 1;
        int ifast = 2;
        int curSum = islow + ifast;
        while(islow < ifast){

            if(curSum<sum){
                ifast++;
                curSum += ifast;
            }

            if(curSum == sum && islow+1<=ifast){
                vector<int> temp;
                for(int i=islow; i<=ifast; i++)
                    temp.push_back(i);
                ans.push_back(temp);

                // note: there mush be add a new value to extend the result.
                curSum -= islow;
                islow++;
            }

            if(curSum > sum){
                curSum -= islow;
                islow++;
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int> > ans = Solution().FindContinuousSequence(3);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}