#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0;
        int r=0;
        int count = 0;
        int ans = 0;
        while(r<nums.size()){
            m[nums[r]]++;
            count=max(count,m[nums[r]]);
            while(count>k){
                if(m[nums[l]]==count){
                    count--;  
                }
                m[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};