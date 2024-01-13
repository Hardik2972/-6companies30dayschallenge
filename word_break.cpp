#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int recursion(string s,int i,int j,unordered_map<string,int>& m,auto& dp){
        if(i==s.size() && j==s.size()){
            return true;
        }
        if(j==s.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string temp = s.substr(i,j-i+1);
        if(m.find(temp)==m.end()){
            return dp[i][j]=recursion(s,i,j+1,m,dp);
        } 
        else{
            int takeIt = recursion(s,j+1,j+1,m,dp);
            int notTakeIt = recursion(s,i,j+1,m,dp);
            return dp[i][j]=(takeIt || notTakeIt);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        unordered_map<string,int> m;
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]++;
        }
        return recursion(s,0,0,m,dp);
    }
};