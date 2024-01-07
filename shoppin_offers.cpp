#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    int recursion(int i,vector<vector<int>>& special, vector<int> needs,vector<int>& price,auto& dp){
        if(i==special.size()){
            int total = 0;
            for(int i=0;i<price.size();i++){
                total+=(needs[i]*price[i]);
            }
            
            return total;
        }
        if(dp.find(i)!=dp.end() && dp[i].find(needs)!=dp[i].end()) return dp[i][needs];
        int notTakeIt = recursion(i+1,special,needs,price,dp);
        int takeIt = 1e9;
        vector<int> temp = needs;
        for(int j=0;j<needs.size();j++){
            if((temp[j]-special[i][j])>=0){
                temp[j]=temp[j]-special[i][j];
            }
            else{
                return dp[i][needs]=notTakeIt;
            }
        }
        takeIt = special[i][needs.size()] + recursion(i,special,temp,price,dp);
        
        return dp[i][needs]=min(notTakeIt,takeIt);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int,map<vector<int>,int>> dp;
        return recursion(0,special,needs,price,dp);
        
    }
};