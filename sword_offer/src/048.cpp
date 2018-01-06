/*
	[矩阵中的路径]

    [题目]
	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
	路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
	如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
	例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
	因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

    [解析]
    算法上没有什么难点，掌握回溯法，实现过程注意细节。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution{
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(matrix == NULL || str == NULL)
            return false;

        bool* visited = new bool[rows*cols];
        for(int i=0; i<rows*cols; i++)
            visited[i] = false;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                bool ans = hasPathBacktracking(matrix, visited, i, j, rows, cols, str);
                if(ans)
                    return ans;
            }
        }

        return false;
    }

    bool hasPathBacktracking(char* matrix, bool* visited, int i, int j, int rows, int cols, char* str){
        if(str == NULL)
            return false;
        if(*str == '\0')
            return true;
        
        if(i<0 || i>=rows || j<0 || j>= cols)
            return false;

        bool ans = false;
        int index = i*cols + j;
        if(!visited[index] && matrix[index] == *str){
            visited[index] = true;

            ans = hasPathBacktracking(matrix, visited, i-1, j, rows, cols, str+1)
               || hasPathBacktracking(matrix, visited, i+1, j, rows, cols, str+1)
               || hasPathBacktracking(matrix, visited, i, j-1, rows, cols, str+1)
               || hasPathBacktracking(matrix, visited, i, j+1, rows, cols, str+1);

            visited[index] = false;
        }

        return ans;

    }
};

int main()
{
    return 0;
}