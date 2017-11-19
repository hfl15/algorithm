/*
	[左旋转字符串]

	汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
	对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
	例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    string LeftRotateString(string str, int n){
        //return LeftRotateStringAssistSpace(str, n);
        //return LeftRotateStringInplace(str, n);
        return LeftRotateStringReverse(str, n);
    }

    // time-O(n), space-O(n)
    string LeftRotateStringAssistSpace(string str, int n){
        int ns = str.size();
        n = n % ns;
        string strHelp = str;

        for(int i=0; i<ns; i++){
            // move the str[i] to the right place
            int ir = (i-n)%ns;
            if(ir < 0)
                ir += ns;
            strHelp[ir] = str[i];
        }

        return strHelp;
    }

    // time-O(n), space-O(1)
    string LeftRotateStringInplace(string str, int n){
        int ns = str.size();
        int count = 0;

        for(int start=0; count < ns && start < ns; start++){
            char prev = str[start];
            int icur = start;
            do{
                int inext = (icur - n) % ns;
                if(inext < 0)
                    inext += ns;
                swap(prev, str[inext]);
                icur = inext;
                count++;
            }while(icur != start);
        }

        return str;
    }

    // time-O(n), space-O(1)
    string LeftRotateStringReverse(string str, int n){
        reverse(str, 0, str.size()-1);
        reverse(str, 0, str.size()-n-1);
        reverse(str, str.size()-n, str.size()-1);

        return str;
    }

    void reverse(string &str, int left, int right){
        if(left >= right)
            return;
        while(left<=right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }


};

int main()
{
    cout << Solution().LeftRotateString("abcXYZdef", 3) << endl;
    return 0;
}