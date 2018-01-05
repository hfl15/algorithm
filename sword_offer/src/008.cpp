/*
	[矩形覆盖]
    [题目]
	我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
	请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

    [解析]
    假设覆盖总共有 f[n] 种方法，可以得递归式：
    f[n] = f[n-1] + f[n-2] // 当小矩形竖着放时，大矩形还剩下 n-1 的规模，当小矩形横着放时，大矩形还剩下 n-2 的规模。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int rectCover(int number) {

        // f[n] = f[n-1] + f[n-2]
        // f[1] = 1, f[2] = 2;
        if(number == 0) // special case
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;

        int f1 = 1;
        int f2 = 2;
        for(int i=3; i<=number; i++){
            int temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }

        return f2;
    }
};

int main()
{
    return 0;
}