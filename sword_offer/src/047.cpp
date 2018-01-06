/*
	[替换空格]
    
    [题目]
	请实现一个函数，将一个字符串中的空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

    [解析]
    字符串处理。关键点：不必思维定势，遍历不一定都从前往后，也可以从后往前。注意：指针的检查，输入的数组必需保证有足够的空间作为扩充使用！
*/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    void replaceSpace(char *str, int length){
        if(str == NULL)
            return;

        int countSpace = 0;
        for(int i=0; i<length; i++){
            if(str[i] == ' ')
                countSpace++;
        }

        int lengthNew = length + 2*countSpace; // conver space to %20, so each space corespond 2 increment on length
        for(int inew=lengthNew-1, icur=length-1; icur>=0; icur--){
            if(str[icur] == ' '){
                str[inew--] = '0';
                str[inew--] = '2';
                str[inew--] = '%';
            }else{
                str[inew--] = str[icur];
            }
        }
    }
};

int main()
{
    return 0;
}