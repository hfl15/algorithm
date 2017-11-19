/*
	[孩子们的游戏（圆圈中最后剩下的数字）]

	孩子们的游戏，圆圈中最后剩下的数字。n 个小朋友，从 0 开始编号到 n-1，每次都删除第 m 个小朋友。
	其中删除以后从被删除结点的下一个结点开始从 0 开始编号。
	最后只剩下一个小朋友时游戏结束，这个小朋友的编号是多少？
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution{
public:
    int LastRemaining_Solution(int n, int m){
        //return LastRemainingList(n, m);
        return LastRemainingDynamic(n, m);
    }

    // time-O(m*n), spcae-O(n)
    int LastRemainingList(int n, int m){
        if(n <= 0 || m <= 0)
            return -1;
        list<int> children;
        for(int i=0; i<n; i++){// no. from 0 to (n-1)
            children.push_back(i);
        }

        auto it = children.begin(); // no. 0
        for(int k=0; k<n-1; k++){
            // Note: while(children.size() > 1) is not appropriate, because the complexity of children.size() is up to linear
            // until now, it point to the 0-th child
            for(int i=1; i<m; i++){ // loop from th 1-th child to m-1
                it++;
                if(it == children.end())
                    it = children.begin();
            }

            // until now, it point to the (m-1)-th child
            it = children.erase(it); // erase will return the following iterator
            if(it == children.end())
                it = children.begin(); 
        }

        return children.front();
    }

    // time-O(n), space-O(1)
    int LastRemainingDynamic(int n, int m){
        if(n<=0 || m<=0)
            return -1;

        int f = 0; // f[1,m] = 0
        for(int i=2; i<=n; i++){
            // calculate f[i,m]
            f = (f+m)%i;
        }

        return f;
    }
};

int main()
{
    return 0;
}