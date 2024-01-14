#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int recursion(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(i==nums1.size() || j==nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first = recursion(i+1,j,nums1,nums2,dp);
        int second = recursion(i,j+1,nums1,nums2,dp);
        int third = recursion(i+1,j+1,nums1,nums2,dp);
        if(nums1[i]==nums2[j]) cout<<i<<"  "<<j<<endl;
        int add = 0;
        if(nums1[i]==nums2[j] && (i+1==nums1.size() || j+1==nums2.size() || nums1[i+1]==nums2[j+1])){
            add = 1;
        }
        return dp[i][j]=max(first,max(second,third+add));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return recursion(0,0,nums1,nums2,dp);
    }
};