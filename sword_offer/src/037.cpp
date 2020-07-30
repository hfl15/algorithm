/*
	[整数中1出现的次数（从1到n的整数中1出现的次数）]

	求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
	为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
	ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		int count = 0;
		int factor = 1;
		int n_low = 0;
		int n_cur = 0;
		int n_high = 0;
		int n_high_cur = n / factor;
		while(n_high_cur != 0){
			n_high = n_high_cur / 10;
			n_cur = n_high_cur % 10;
			n_low = n - n_high_cur*factor; 

			//cout << n_high << " " << n_cur << " " << n_low << endl;

			switch (n_cur)
			{
			case 0: 
				count += n_high*factor;
				break;
			case 1:
				count += n_high*factor + n_low + 1;
				break;
			default:
				count += (n_high+1)*factor;
				break;
			}

			factor *= 10; // loop from low to high
			n_high_cur = n / factor;
		}

		return count;
    }
};

int main()
{
	int n;
	cin >> n;
	
	Solution s = Solution();
	int ans = s.NumberOf1Between1AndN_Solution(n);
	cout << ans << endl;

	return 0;
}
