/*
	[构建乘积数组]
    
    [题目]
	给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
	其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

    [解析]
    参看代码
    时间复杂度-O(n)，空间复杂度-O(n)。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> multiply(const vector<int>& A){
        if(A.size() < 2)
            return vector<int>();

        int n = A.size();
        vector<int> mulForward(n,0); // mulForward[i] = A[0]*...*A[i]
        vector<int> mulBackward(n,0); // mulBackward[i] = A[i]*...*A[n-1]

        mulForward[0] = A[0];
        for(int i=1; i<n; i++)
            mulForward[i] = mulForward[i-1] * A[i];
        mulBackward[n-1] = A[n-1];
        for(int i=n-2; i>=0; i--)
            mulBackward[i] = A[i]*mulBackward[i+1];

        vector<int> B(n, 0);
        B[0] = mulBackward[1];
        for(int i=1; i<n-1; i++){
            B[i] = mulForward[i-1]*mulBackward[i+1];
        }
        B[n-1] = mulForward[n-2];

        return B;
    }
};

int main()
{
    return 0;
}