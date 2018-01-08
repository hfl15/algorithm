/*
	
	[371. Sum of Two Integers - easy]

	[description]
	Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
	Example:
		Given a = 1 and b = 2, return 3.

	[solution]
	a person make a summary about how to use bit manipulation to solve problems easily and efficency.

*/

#include <iostream>

using namespace std;

class Solution{
public:
	int getSum(int a, int b){
		if(a == 0)
			return b;
		if(b == 0)
			return a;

		while(b){
			int carry = a & b; // Note: we need to get the carry before change the value of a.
			a = a ^ b;
			b = carry << 1; // carry
		}

		return a;
	}
};

int main()
{
	cout << Solution().getSum(1, 2) << endl;
	return 0;
}