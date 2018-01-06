/*
	[字符串的排序]
    
    [题目]
	输入一个字符串,按字典序打印出该字符串中字符的所有排列。
	例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
	输入描述：
		输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

    [解析]
    注意：
        1. 输入字符串中有重复，因此在求全排列的时候要避免这样的情况。
            - 如下面代码一样避免。
            - 使用 set 存储结果，多一次 copy 操作，从 set 复制到 vector 中。
        2. 返回结果要以字典序排序。

*/

class Solution{
public:
    vector<string> Permutation(string str){
        vector<string> ans;
        if(str.empty())
            return ans;
        PermutationRecursive(str, 0, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }

    void PermutationRecursive(string &str, int index, vector<string> &ans){
        if(index >= str.size()){
            ans.push_back(str);
            return;
        }

        PermutationRecursive(str, index+1, ans);
        for(int i=index+1; i<str.size(); i++){
            if(str[i] == str[index])
                continue;
            swap(str[index], str[i]);
            PermutationRecursive(str, index+1, ans);
            swap(str[index], str[i]);
        }
    }
};