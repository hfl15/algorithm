/*
	[数值的整数次方]
        
    [题目]
	给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

    [解析]
    主要是要注意边界条件的处理。
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

class Solution{
public:
    double Power(double base, int exponent) {
        // special case
        if(base == 0 && exponent == 0)
            return 0;
        if(base == 0 && exponent < 0 ) // 严格来说，两个 double 类型的数是否相等，应当通过判断他们的差值是否为很小的数来判断。计算机存储浮点数是有误差的。 
            return numeric_limits<int>::max();

        double ans = PowerPositive(base, abs(exponent));
        if(exponent < 0)
            ans = 1.0/ans;
        return ans;
    }

    double PowerPositive(double base, int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;

        double temp = PowerPositive(base, exponent/2); // exponent/2 可以通过移位操作来实现，更高效，等价于 exponent >> 1 
        if((exponent & 1) == 1){
            return temp*temp*base;
        }else{
            return temp*temp;
        }
    }
};

int main()
{
    return 0;
}
