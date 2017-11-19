/*
	[数组中只出现一次的数字]

	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
        if(data.empty()){
            *num1 = *num2 = 0;
            return;
        }

        // find the xor of this two different number, assume num1 and num2
        int num = 0;
        for(int i=0; i<data.size(); i++)
            num ^= data[i];

        int flag = 1;
        while(flag){
            if((num & flag))
                break;
            flag <<= 1;
        }

        // split data into two subset, based on the bit of flag,
        // by this way we can divid these two different number into two subset

        int cond1 = 0;
        int cond2 = 0;
        for(int n : data){
            if((n & flag)){
                cond1 ^= n;
            }else{
                cond2 ^= n;
            }
        }

        *num1 = cond1;
        *num2 = cond2;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    vector<int> data;
    int *num1 = new int(), *num2 = new int();
    int cur;
    while(cin >> cur){
        data.push_back(cur);
    }
    cout << data.size() << endl;
    Solution().FindNumsAppearOnce(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    fclose(stdin);
    return 0;
}