#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int i = 0;
       int j = 0;
       int count = 0;
       int ans = 0;
       while(j<nums.size()){
           if(nums[j]%2!=0){
               count++;
           }
           while(count>k){
               if(nums[i]%2!=0) count--;
               i++;
           }
           if(count==k){
               int tempCount = 0;
               int k = i;
               while(nums[k]%2==0){
                   tempCount++;
                   k++;
               }
               ans+=tempCount+1;
           }
           j++;
       } 
       return ans;
    }
};