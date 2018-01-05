/*
	[把字符串转换为整数]

    [题目]
	将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
	输入描述：输入一个字符串,包括数字字母符号,可以为空
	输出描述：如果是合法的数值表达则返回该数字，否则返回0

    [解析]
    没有什么算法。但要写 bug free 的代码还是有难度，边界条件要考虑清楚！！
    合理的字符，上溢，下溢。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution{
public:
    int StrToInt(string str){
        if(str.empty())
            return 0;
        // valid number : [+/-]number
        int icur = 0;

        // sign
        int sign = 1;
        if(str[icur] == '+' || str[icur] == '-'){
            if(str[icur] == '-')
                sign = -1;
            icur++;
        }

        // number
        int ansAbs = 0;
        for( ; icur<str.size(); icur++){
            int num = ctoi(str[icur]);
            if(num < 0) // nonvalid number
                return 0;
            long temp = sign*(ansAbs*10 + num);
            if(temp < numeric_limits<int>::min() || temp > numeric_limits<int>::max())
                return 0;
            ansAbs = temp / sign;
        }

        return ansAbs * sign;
    }

    int ctoi(char ch){
        if(ch>='0' && ch<='9')
            return ch-'0';
        else
            return -1;
    }
};

int main()
{
    return 0;
}