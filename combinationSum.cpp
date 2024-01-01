#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void recursion(int i,int target,vector<vector<int>>& ans,vector<int> temp,int k,int next){
        if(i==k && target==0){
            ans.push_back(temp);
            return ;
        }
        else if(target<0 || i==k) return ;
        for(int j=next+1;j<10;j++){
            temp.push_back(j);
            recursion(i+1,target-j,ans,temp,k,j);
            temp.pop_back();
        }
        

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        recursion(0,n,ans,{},k,0);
        return ans;
    }
};