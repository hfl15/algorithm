/*

	[344. Reverse String - easy]

	[description]
	Write a function that takes a string as input and returns the string reversed.

	[example]
	Given s = "hello", return "olleh".	

	[solution]
	1. with auxiliary space
	2. optimal solution, swap the two end character in each time. The realization as follow.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string reverseString(string s){
		int i=0, j=s.size()-1;
		while( i<j ){
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
};

int main()
{
	cout << Solution().reverseString("hello") << endl;
	return 0;
}