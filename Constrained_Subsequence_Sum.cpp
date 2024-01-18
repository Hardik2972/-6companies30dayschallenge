#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        priority_queue<pair<int,int>> q;
        q.push({nums[0],0});
        int ans = nums[0];
        for(int i=1;i<n;i++){
            while(!q.empty() && i-q.top().second>k){
                q.pop();
            }
            dp[i]=max(dp[i],dp[i]+q.top().first);
            q.push({dp[i],i});
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};