/*
	[表示数值的字符串]

    [题目]
	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
	例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
	但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

    [解析]
    正确的形式[]表示可有可无/表示其中任一一个。
    [sign]integer[.integer][e/E [sign] integer]
    理清思路，每一种情况考虑到位。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool isNumeric(char* string){
        if(string == NULL || *string=='\0')
            return false;
        //cout << string << endl;

        char* pCur = string;
        // sign
        if(*pCur == '-' || *pCur == '+'){
            pCur++;
            if(*pCur == '\0')
                return false;
        }
        //cout << "finish sign: " << *pCur << endl;

        // integral part
        skipInteger(pCur);
        if(*pCur == '\0')
            return true;
        //cout << "finish integral part: " << *pCur << endl;

        // fractional part
        if(*pCur == '.'){
            pCur++;
            if(*pCur == '\0')
                return false;

            skipInteger(pCur);
        }
        //cout << "finish fractional part: " << *pCur << endl;

        // exponent part
        if(*pCur == 'e' || *pCur == 'E'){
            pCur++;
            if(*pCur == '\0')
                return false;

            // sign
            if(*pCur == '-' || *pCur == '+'){
                pCur++;
                if(*pCur == '\0')
                    return false;
            }

            // integer
            skipInteger(pCur);
        }
        //cout << "finish exponent part: " << *pCur << endl;

        return *pCur == '\0';

    }

    void skipInteger(char* &pCur){
        while(*pCur != '\0' && isInteger(*pCur)){
            pCur++;
        }
    }

    bool isInteger(char ch){
        return ch>='0' && ch<='9';
    }
};

int main()
{
    char* str="+100.123E-1";
    cout << Solution().isNumeric(str) << endl;
    return 0;
}