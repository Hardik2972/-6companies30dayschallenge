#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int recursion(int i,int mask,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(mask==(1<<n)-1) {
            // cout<<"hi"<<endl;
            return 1;
        }
        if(dp[i+1][mask]!=-1) return dp[i+1][mask];
        int take = 0;
        for(int j=0;j<n;j++){
            if((i==-1 || nums[i]%nums[j]==0 || nums[j]%nums[i]==0 ) && !(mask&(1<<j))){
                int temp = mask | (1<<j);
                // cout<<j<<"  "<<temp<<endl;
                take =(take + recursion(j,temp,nums,dp))%(int)(1e9+7);
            }
        }
        return dp[i+1][mask]=take;
    }
    int specialPerm(vector<int>& nums) {
        // cout<<(1<<nums.size())<<"hi this ";
        int n =nums.size();
        vector<vector<int>> dp(n+1,vector<int>((1<<n),-1));
        return recursion(-1,0,nums,dp);
    }
};