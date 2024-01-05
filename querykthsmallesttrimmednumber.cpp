#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int function(vector<string>& nums,vector<int>& querie){
        int trim = querie[1];
        int kth = querie[0];
        priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>>> q;
        int startIndex = nums[0].size()-trim;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i].substr(startIndex),i});
        }
        int i =0;
        int result = -1;
        while(!q.empty() && i<kth){
             result = q.top().second;
             q.pop();
             i++;
        }
        return result;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(function(nums,queries[i]));
        }
        return ans;
    }
};