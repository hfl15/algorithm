/*
	[把数组排成最小数]

	输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
	例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    string PrintMinNumber(vector<int> numbers){
        vector<string> strs(numbers.size());
        for(int i=0; i<numbers.size(); i++){
            strs[i] = to_string(numbers[i]);
        }

        sort(strs.begin(), strs.end(), comp);
        string ans;
        for(string s : strs){
            ans.append(s);
        }

        return ans;
    }

    static bool comp(string str1, string str2){
        string str12 = str1 + str2;
        string str21 = str2 + str1;

        return str12 < str21;
    }
};

int main()
{
    return 0;
}