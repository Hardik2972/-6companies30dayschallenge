#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = nums.size()-1;
        int i = j/2;
        int start = i;
        vector<int> num;
        while(j>start && i>=0){
            num.push_back(nums[i--]);
            num.push_back(nums[j--]);
        }
        while(i>=0){
            num.push_back(nums[i--]);
        }
        nums = num;
        
    }
};