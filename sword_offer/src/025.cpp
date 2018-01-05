/*
	[数据流的中位数]
    
    [题目]
	如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
	如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

    [解析]
    注意题目中的关键字“数据流”。
        方法1: 
            可以考虑每次需要获取中位数时都在当前数组中进行查找，使用 top k 的思想最优是 O(n) 的复杂度找到，
            如果查询次数多的话，那么复杂度会很高，数据不断增加，数组是乱序的。
        方法2: 
            维持一个有序的数组，新数到来时插入到有效的位置，顺序插入复杂度是 O(n)，
            最优可以使用二分查找在 O(log(n)) 复杂度内找到插入的位置，但插入时需要移动数字，
            复杂度还是O(n)，当插入操作很多时候复杂度也会很大。
            
    最优解：
        插入时间复杂度： O(log(n/2))；查询复杂：O(1)。
        
        核心思想是将数字分成左右两个部分，并且两个部分元素的个数最多不超过1，左边部分小于等于中位数，而右边部分大于等于中位数。
        
        左边部分使用最大堆存储，max_heap，右边部分使用最小堆存储 min_heap。
        （1）当两个堆的元素个数相等时，或min_heap中元素个数较少时，将新的数插入到右边部分，
        即 min_heap 中，此时如果要插入的数 num 小于堆顶，那么就说明 num 应该被放到左半部分，
        这个时候需要将 num 插入到 max_heap 中，然后获取 max_heap 中当前的最大值并弹出，
        这才方可将弹出的数插入到 min_heap 中。（2）当 max_heap 个数较少时，新增数加入，过程与前面描述类似。

        查找时：如果 max_heap 和 min_heap 个数相等则说明数组长度为偶数，返回两个堆顶的均值即可；
        否则，根据规则肯定是 min_heap 中多处一个数，这个时候返回 min_heap 的堆顶。

    实现细节：
        可以使用 C++ 中的 priority_queue 实现堆。也可以使用


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // for less and greater function

using namespace std;

class Solution{
public:
    void Insert(int num){
        if(max_heap.size() < min_heap.size()){
            // insert into max_heap
            if(!max_heap.empty() && max_heap.front() < num){
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                num = min_heap.front();
                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<int>());

        }else{
            // insert into min_heap
            if(!min_heap.empty() && min_heap.front() > num){
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<int>());
                num = max_heap.front();
                pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        }
        
    }

    double GetMedian(){
        if(min_heap.size() == max_heap.size() && !min_heap.empty()){
            return (min_heap.front() + max_heap.front())*1.0 / 2.0;
        }else{ 
            return min_heap.front();
        }
    }

private:
    vector<int> min_heap; // right part, value large than and equal to median
    vector<int> max_heap; // left part, value less than and equal to median
    // insure min_heap.size() >= max_heap.size()
    // and min_heap.size() - max_heap.size() <= 1

};

int main()
{
    return 0;
}