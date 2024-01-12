#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int lastIndex = 0;
        int maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }

        }
        for(int i=0;i<n;i++){
            cout<<hash[i]<<"  ";
        }
        vector<int> ans ;
        ans.push_back(nums[lastIndex]);
        while(lastIndex!=hash[lastIndex]){
            lastIndex=hash[lastIndex];
            ans.insert(ans.begin(),nums[lastIndex]);
            
        }
        return ans;
    }
};