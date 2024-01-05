#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<access_times.size();i++){
            m[access_times[i][0]].push_back(access_times[i][1]);
        }
        vector<string> ans;
        for(auto it:m){
            sort(it.second.begin(),it.second.end());
            int size = it.second.size();
            for(int i=0;i<=size-3;i++){

                int start = stoi(it.second[i].substr(0,2))*60 + stoi(it.second[i].substr(2,2));
                int end = stoi(it.second[i+2].substr(0,2))*60 + stoi(it.second[i+2].substr(2,2));
                if((end-start)<60){ 
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};