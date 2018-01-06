/*
	[第一个出现一次的字符]
    
    [题目]
	在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

    [解析]
    典型的 hash 应用，当知道有限范围时可以自己定义数组当作 hash 表。
    这里字符串由字母组成，因此只需要 ascii 码的长度即可满足。
    当额外空间为一个较小的固定常数时可认为是常数空间的开销。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    // time - O(n), space = O(256)
    int FirstNotRepeatingChar(string str) {
        const int MAXSIZE = 256;
        vector<int> hash(MAXSIZE, 0);

        for(char c : str){
            hash[c]++;
        }

        for(int i=0; i<str.size(); i++){
            if(hash[str[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    return 0;
}