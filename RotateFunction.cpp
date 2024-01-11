#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[0]+=nums[i]*i;

        }
        int n = nums.size();
        int maxi = dp[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1] + sum - (n*nums[n-i]);
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};