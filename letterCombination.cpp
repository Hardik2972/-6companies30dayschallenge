#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    void recursion(int i,vector<string>& ans,string temp,string & digits){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string current = m[digits[i]];
        for(int j=0;j<current.size();j++){
            temp+=current[j];
            recursion(i+1,ans,temp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return{};
        recursion(0,ans,{},digits);
        return ans;
    }
};