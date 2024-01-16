#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;
        map<int,int> ma;
        for(int i=0;i<matches.size();i++){
            m[matches[i][0]]++;
            ma[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it:ma){
            if(it.second==1){
               ans[1].push_back(it.first);
            }
           
            
        }
        for(auto it:m){
             if(ma.find(it.first)==ma.end()){
                ans[0].push_back(it.first);
            }
        }
        
        return ans;
    }
};