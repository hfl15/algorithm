/*
	[字符流中第一个不重复的字符]
    
    [题目]
	题目描述:
		请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
        第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
	输出描述:
		如果当前字符流没有存在出现一次的字符，返回#字符。

    [解析]
    注意是字符流中截至当前第一个只出现一次的字符。我们需要动态的存储各字符的当前状态，对于只出现一次的字符记录其下标，这样才能知道字符出现的先后次序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

#define MAX_SIZE 256
#define STATE_UNSET  -1 // indicate the character has not found
#define STATE_RESET  -2 // indicate the character has been found multiple times 

class Solution{
public:
    // initialization
    Solution(){
        this->states = vector<int>(MAX_SIZE, STATE_UNSET);
        this->curIndex = 0;
    }
    // Insert one char from stringstream
    void Insert(char ch){
        if(this->states[ch] == STATE_UNSET){
            this->states[ch] = this->curIndex;
            this->curIndex++;
        }else{
            this->states[ch] = -2;
        }
    }

    // return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        char ans = '#';
        int minIndex = numeric_limits<int>::max();
        for(int i=0; i<this->states.size(); i++){
            if(this->states[i] >= 0 && this->states[i] < minIndex){
                ans = (char)i;
                minIndex = this->states[i];
            }
        }

        return ans;
    }

private:
    // states[i] >=0 indicate the character has been found only once 
    // and the value is the index of character in stringstream
    vector<int> states; 
    int curIndex;
};

int main()
{
    string str = "google";
    Solution s = Solution();
    for(int i=0; i<str.size(); i++){
        s.Insert(str[i]);
        cout << s.FirstAppearingOnce() << endl;
    }
    return 0;
}