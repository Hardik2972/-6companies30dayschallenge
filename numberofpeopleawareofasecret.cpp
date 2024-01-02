#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int recursion(int i,int j,int n,int delay,int forget,vector<vector<int>>& dp){
        if(i<=forget && j==n) return 1;
        if(i==forget) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        if(i>=delay){
            int l = recursion(i+1,j+1,n,delay,forget,dp);
            int r = recursion(1,j+1,n,delay,forget,dp);
            return dp[i][j]=(l+r)%(int)(1e9+7);
        }
        return dp[i][j]=recursion(i+1,j+1,n,delay,forget,dp);
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(forget,vector<int>(n,-1));
        return recursion(1,1,n,delay,forget,dp);
    }
};