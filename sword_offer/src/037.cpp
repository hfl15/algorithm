/*
	[整数中1出现的次数（从1到n的整数中1出现的次数）]

	求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
	为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
	ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int NumberOf1Between1AndN_Solution(int n){
        int icout = 0;
        int ihight = 0;
        int ilow = 0;
        int icur = 0;
        int ifactor = 1;

        while( n / ifactor != 0){
            ihight = n / (ifactor*10);
            icur = (n / ifactor) % 10;
            ilow = n - (n / ifactor) * ifactor;

            switch(icur){
                case 0 : 
                    icout += ihight*ifactor;
                    break;
                case 1 :
                    icout += ihight*ifactor + ilow + 1;
                    break;
                default:
                    // icur > 1
                    icout += (ihight+1)*ifactor;

            }

            ifactor *= 10; // scan from the low-order to high-order
        }

        return icout;
    }
};

int main()
{
    return 0;
}