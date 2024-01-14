#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int recursion(int i,string& s,unordered_map<string,int>& m,vector<int>& dp){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX;
        string temp = "";
        for(int j=i;j<s.size();j++){
            temp.push_back(s[j]);
            if(m.find(temp)==m.end()){
                int n = temp.size();
                mini=min(mini,n+recursion(j+1,s,m,dp));
            }
            else{
                mini=min(mini,recursion(j+1,s,m,dp));
            }
        }
        return dp[i]=mini;
 
    } 
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> m;
        vector<int> dp(s.size(),-1);
        for(int i=0;i<dictionary.size();i++){
            m[dictionary[i]]++;
        }
        return recursion(0,s,m,dp);
    }
};