#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int convertable = 0;
        if(nums.size()%2==0){
            convertable = (nums[nums.size()/2]+nums[(nums.size()/2)-1])/2;
        }
        else{
            convertable = nums[nums.size()/2];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-convertable);
        }
        return ans;
    }
};