/*
	[顺时针打印矩阵]
    
    [题目]
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
	例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
	则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

    [解析]
    技巧：
        一个矩阵可以使用对角线的两个点来唯一表示
    注意：
        只剩下一行或只剩下一列的特殊情况
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> printMatrix(vector<vector<int> > matrix){
        if(matrix.empty())
            return vector<int>();

        vector<int> ans;
        int si = 0, sj = 0;
        int ei = matrix.size()-1;
        int ej = matrix[0].size()-1;

        while(si<=ei && sj<=ej){
            // print a cycle
            // the first row
            for(int j=sj; j<=ej; j++)
                ans.push_back(matrix[si][j]);

            // the rightmost column
            for(int i=si+1; i<=ei; i++)
                ans.push_back(matrix[i][ej]);

            // the last row if have
            if(si < ei){
                for(int j=ej-1; j>=sj; j--)
                    ans.push_back(matrix[ei][j]);
            }

            // the leftmost column if have
            if(sj < ej){
                for(int i=ei-1; i>si; i--)
                    ans.push_back(matrix[i][sj]);
            }

            si++;
            sj++;
            ei--;
            ej--;
        }

        return ans;
    }
};

int main()
{
    return 0;
}