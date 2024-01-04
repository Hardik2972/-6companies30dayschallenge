#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int recursion(int i,int j,int steps,int endPos,vector<vector<int>>& dp,int& diff){
        if(i==endPos && j==steps) return 1;
        else if(j>=steps) return 0;
        if(dp[i+diff][j]!=-1) return dp[i+diff][j];
        int left = recursion(i-1,j+1,steps,endPos,dp,diff);
        int right =recursion(i+1,j+1,steps,endPos,dp,diff);
        return dp[i+diff][j]=(left+right)%(int)(1e9+7);
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(2*k,vector<int>(k,-1));
        int diff = k - startPos;
        return recursion(startPos,0,k,endPos,dp,diff);
    }
};