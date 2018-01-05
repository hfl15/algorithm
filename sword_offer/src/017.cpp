/*
	[左旋转字符串]

    [题目]
	汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
	对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
	例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

    [解析]
    方法 1: 
        循环左移 k 位，也就是每次讲最开始的数移动到最后，而从第 2 个数开始依次向前移动 1 位，
        这样的操作进行 k 次即可得到解。样例的移动过程：abcXYZdef-->bcXYZdefa-->cXYZdefab-->XYZdefabc。
        时间复杂度：每一次移位都需要移动 n 个数，k 次的时间为 O(k*n)；空间复杂度：O(1)
    方法 2: 
        将每一个字符一次到位，移动到合适的位置，假设字符串长度为 n，对于第 i 个字符，移动后的位置应该为 (i-k)%n。
        时间复杂度：只需要遍历一次，O(n)；空间复杂度：需要一个额外的辅助数组，O(n)
    方法 3: 
        基于方法 2 的改进，对于第 i 个字符，使用prev保存，我们将其移动到 next=(i-k)%n，
        此时 next 位置是被占用的，同理我们交换 prev 和 S[j] 的值，这个时候 S[j] 的字符已经摆放正确，
        我们继续处理 prev中的字符，让 i=j，继续计算next=(i-k)%n，这样的过程必然会形成一个环又回到第一个数的位置，
        每一次操作能正确摆放一个字符，只要操作 n 次就可以完成任务（可以参考 leetcode：189. Rotate Array 的解释）。
        示例：
            abcXYZdef, prev = a, i=0, next=(i-3)%9=6,
            abcXYZaef, prev = d, i=6, next=(i-3)%9=3,
            abcdYZaef, prev = X, i=3, next=(i-3)%9=0,
            XbcdYZaef, 因为 next==start == 0，结束一次环中的移动，操作 3 次，3 个字母摆放正确。
            新一轮循环从 start++，即 1 开始重复上面的过程，直到摆放的字母数 == n 时结束。
    方法 4: 
        借助字符串逆袭解决问题（时间复杂度O(n)，空间复杂度O(1)）
        示例：
            将原字符串逆序：abcXYZdef --> fedZYXcba ([0,n-1]=[0,8] 逆序)
            将前半部分逆序：fedZYXcba --> XYZdefcba ([0,n-k-1]=[0,5] 逆序)
            将后半部分逆序：XYZdefcba --> XYZdefabc ([n-k,n-1]=[6,8] 逆序)
    注意：
        1. k > n 可能存在，循环移位，我们可以在开始令 k=k%n。
        2. 在取模运算过程中 next = i%n < 0，将 next 转成同余的正数 next = next + n

    code:
        只实现时间复杂度为 O(n) 的方法。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    string LeftRotateString(string str, int n){
        //return LeftRotateStringAssistSpace(str, n);
        //return LeftRotateStringInplace(str, n);
        return LeftRotateStringReverse(str, n);
    }

    // time-O(n), space-O(n)
    string LeftRotateStringAssistSpace(string str, int n){
        int ns = str.size();
        n = n % ns;
        string strHelp = str;

        for(int i=0; i<ns; i++){
            // move the str[i] to the right place
            int ir = (i-n)%ns;
            if(ir < 0)
                ir += ns;
            strHelp[ir] = str[i];
        }

        return strHelp;
    }

    // time-O(n), space-O(1)
    string LeftRotateStringInplace(string str, int n){
        int ns = str.size();
        int count = 0;

        for(int start=0; count < ns && start < ns; start++){
            char prev = str[start];
            int icur = start;
            do{
                int inext = (icur - n) % ns;
                if(inext < 0)
                    inext += ns;
                swap(prev, str[inext]);
                icur = inext;
                count++;
            }while(icur != start);
        }

        return str;
    }

    // time-O(n), space-O(1)
    string LeftRotateStringReverse(string str, int n){
        reverse(str, 0, str.size()-1);
        reverse(str, 0, str.size()-n-1);
        reverse(str, str.size()-n, str.size()-1);

        return str;
    }

    void reverse(string &str, int left, int right){
        if(left >= right)
            return;
        while(left<=right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }


};

int main()
{
    cout << Solution().LeftRotateString("abcXYZdef", 3) << endl;
    return 0;
}