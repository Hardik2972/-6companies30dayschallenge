#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int prev=0;
                int flag = true;
                for(int k=0;k<i;k++){
                    if(prev>=nums[k]){
                        flag=false;
                        break;
                    }
                    else{
                        prev=nums[k];
                    }
                }
                for(int k=j+1;k<nums.size();k++){
                    if(prev>=nums[k]){
                        flag=false;
                        break;
                    }
                    else{
                        prev=nums[k];
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};