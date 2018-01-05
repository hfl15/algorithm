/*
	[数组中只出现一次的数字]

    [题目]
	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

    [解析]

    可以先思考一个简单的问题：
        如果一个数组中只有一个数字出现了一次，其他数字都出现了两次，那么我们只需要进行一次异或，
        根据异或的性质可得，最后的结果肯定是出现一次的数字。

    再回过头来考虑当前的问题，如果我们可以将问题转换成以上描述的这个简单问题，就可以进行求解。
        1. 进行异或，最后得到的结果 num 肯定是这两个只出现 1 次的数字（假设是a，b）的异或结果
        2. 对于 num 中出现 1 的位，表明 a 和 b 在该位上的取值不同，即其中一个取 1，另一个取 0
        3. 我们用一个标志为 flag，找到其中一个使得 a 和 b 不同的位（这里是从左到右的第一，假设为第 k 位）
        4. 根据标志位 flag 来对数组进行划分，那么相同的数字肯定在第 k 位是相等了，这就保证了它们会被分到一起。
           而对于 a 和 b，他们在第 k 位不同，最后肯定会分到不同的划分中。我们得到了两个子集，每个子集满足最考试描述的简单情况。

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