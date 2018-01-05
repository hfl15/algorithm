/*
	[翻转单词顺序]
    
    [题目]
	翻转单词顺序。比如一个句子：“I am a student.” 翻转以后是 “student. a am I”。

    [解析]
    两步完成：
        1. 对整个句子进行翻转
        2. 对单词进行翻转
    注意：别漏掉最后一个单词的处理
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    string ReverseSentence(string str){
        if(str.empty())
            return "";

        // reverse whole string 
        reverse(str, 0, str.size()-1);

        // reverse each word
        int istart = 0;
        int iend = 0;
        while(iend < str.size()){
            if(str[iend] == ' '){
                // a new word
                reverse(str, istart, iend-1);
                istart = iend+1;
                iend = istart;
            }else{
                iend++;
            }
        }

        // the last word
        reverse(str, istart, iend-1);

        return str;
    }

    void reverse(string &str, int left, int right){
        while(left<=right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    return 0;
}