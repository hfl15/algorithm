/*
	
	[description]
	Write a program that outputs the string representation of numbers from 1 to n.
	But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
	For numbers which are multiples of both three and five output “FizzBuzz”.

	[example]
	n = 15,

	Return:
	[
	    "1",
	    "2",
	    "Fizz",
	    "4",
	    "Buzz",
	    "Fizz",
	    "7",
	    "8",
	    "Fizz",
	    "Buzz",
	    "11",
	    "Fizz",
	    "13",
	    "14",
	    "FizzBuzz"
	]

	[solution]
	 Note: The addition operation is more efficent than multiplication operation. So the realization avoid to use mod operation (%).

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	vector<string> fizzBuzz(int n){
		//return firstVersion(n);
		return secondVersion(n);
	}

	// 6 ms
	vector<string> secondVersion(int n){
		// reference: https://leetcode.com/problems/fizz-buzz/discuss/89931
		vector<string> ans;
		int fizz = 3, buzz = 5;
		for(int i=1; i<=n; i++){
			if(i == fizz && i == buzz){
				ans.push_back("FizzBuzz");
				fizz += 3;
				buzz += 5;
			}else if (i == fizz){
				ans.push_back("Fizz");
				fizz += 3;
			}else if (i == buzz){
				ans.push_back("Buzz");	
				buzz += 5;
			}else{
				ans.push_back(to_string(i));
			}
		}
		return ans;
	}

	// 6 ms
	vector<string> firstVersion(int n){
		vector<string> ans;
		for(int i=1; i<=n; i++){
			ans.push_back(to_string(i));
		}

		for(int i=3; i<=n; i+=3){
			ans[i-1] = "Fizz";
		}

		for(int i=5; i<=n; i+=5){
			ans[i-1] = "Buzz";
		}

		for(int i=15; i<=n; i+=15){
			ans[i-1] = "FizzBuzz";
		}

		return ans;
	}
};

int main()
{
	return 0;
}


