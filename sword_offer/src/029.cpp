/*

	[旋转数组的最小数]
    
    [题目]
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
	输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
	NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

    [解析]
    1. 查找的问题，二分查找的变种，我们如何利用循环有序的前题来缩小搜索空间；
    2. 注意特殊情况的处理：当前最左边的值等于最右边的值时无法进一步缩小空间，只能顺序查找。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        if(rotateArray.empty())
            return 0;
        if(rotateArray[0] < rotateArray[rotateArray.size()-1])
            return rotateArray[0];

        int ileft = 0; // point to the maximum in the left ascending part
        int iright = rotateArray.size()-1;  // point to the minimum in the right ascending part

        while(ileft + 1 < iright){
            int mid = ileft + (iright - ileft + 1) / 2;
            if(rotateArray[ileft] == rotateArray[iright]){
                // in this case, we can not shrink the searching space
                // we have no choise but to search in order
                int minVal = rotateArray[ileft];
                for(int i=ileft+1; i<=iright; i++){
                    minVal = min(minVal, rotateArray[i]);
                }
                return minVal;

            }else if (rotateArray[ileft] <= rotateArray[mid]){
                ileft = mid;
            }else{
                // rotateArray[mid] <= rotateArray[iright]
                iright = mid;
            }
        }

        // ileft + 1 == iright
        // so the minimum is iright
        return rotateArray[iright];
    }
};

int main()
{
    return 0;
}
