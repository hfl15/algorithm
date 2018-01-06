/*
	[机器人的运动范围]
    
    [题目]
	地上有一个m行和n列的方格。
	一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
	但是不能进入行坐标和列坐标的数位之和大于k的格子。 
	例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
	但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

    [解析]
    算法上没有什么难点，掌握回溯法，实际上是广度优先遍历，实现过程注意细节。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    int movingCount(int threshold, int rows, int cols){
        int ans = 0;
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        movingCountBacktracking(threshold, rows, cols, 0, 0, visited, ans);

        return ans;
    }

    void movingCountBacktracking(int threshold, int rows, int cols, 
        int i, int j, vector<vector<bool> >& visited, int &ans){
        if(i<0 || i>=rows || j<0 || j>=cols)
            return;
        if(!visited[i][j] && isValid(threshold, i, j)){
            ans++;
            visited[i][j] = true;
            movingCountBacktracking(threshold, rows, cols, i-1, j, visited, ans);
            movingCountBacktracking(threshold, rows, cols, i+1, j, visited, ans);
            movingCountBacktracking(threshold, rows, cols, i, j-1, visited, ans);
            movingCountBacktracking(threshold, rows, cols, i, j+1, visited, ans);
        }
    }

    bool isValid(int threshold, int i, int j){
        return (sumByBit(i) + sumByBit(j)) <= threshold;
    }

    int sumByBit(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
};

int main()
{
    return 0;
}