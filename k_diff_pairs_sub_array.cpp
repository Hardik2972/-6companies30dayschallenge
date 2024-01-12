#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        map<vector<int>,int> o_map;
        for(int i=0;i<nums.size();i++){
            if(m.find(k+nums[i])!=m.end() && i!=m[k+nums[i]]){
                vector<int> temp = {nums[i],k+nums[i]};
                sort(temp.begin(),temp.end());
                if(o_map.find(temp)==o_map.end()){
                    o_map[temp]=1;
                }
            }
            else if(m.find(nums[i]-k)!=m.end() && i!=m[nums[i]-k]){
                vector<int> temp = {nums[i],nums[i]-k};
                sort(temp.begin(),temp.end());
                if(o_map.find(temp)==o_map.end()){
                    o_map[temp]=1;
                }
            }
        }
        int ans = o_map.size();
        return ans;
    }
};