/*
	[正则表达式匹配]
    
    [题目]
	请实现一个函数用来匹配包括'.'和'*'的正则表达式。
	模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
	在本题中，匹配是指字符串的所有字符匹配整个模式。
	例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
    
    [解析]
    题目不难，但一定要细心分析完所有可能的情况。在分析过程中可以借助自动机做图，
    理清状态变换之间的关系。注意考虑边界条件。bug free 还是很难，理清思路再写代码。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    bool match(char* str, char* pattern){
        if(str == NULL || pattern == NULL)
            return false;

        return matchRecursive(str, pattern);
    }

    bool matchRecursive(char* str, char* pattern){
        // str and pattern to the end at the same time
        if(*str == '\0' && *pattern == '\0')
            return true;

        // pattern have been exhaust
        if(*str != '\0' && *pattern == '\0')
            return false;

        // note: until now, pattern must not be the last one
        if(*(pattern+1) == '*'){
            if(*pattern == *str || (*pattern=='.' && *str != '\0')){
                // match
                return matchRecursive(str+1, pattern) 
                    || matchRecursive(str+1, pattern+2)
                    || matchRecursive(str, pattern+2); 
            }else{
                // don't match
                return matchRecursive(str, pattern+2);
            }
        }else{
            if(*pattern == *str || (*pattern=='.' && *str != '\0')){
                // match
                return matchRecursive(str+1, pattern+1);
            }else{
                return false;
            }
        }
    }
};

int main()
{
    return 0;
}