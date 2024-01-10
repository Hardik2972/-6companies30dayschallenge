#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

bool cmp(vector<int>& a,vector<int>& b){
    if(a[0]<b[0]) return true;
    else if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return false;
}

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int ans = 1;
        int n= envelopes.size();
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(temp[temp.size()-1]<envelopes[i][1]){
                temp.push_back(envelopes[i][1]);
            }
            else{
                int index = lower_bound(temp.begin(),temp.end(),envelopes[i][1]) - temp.begin();
                temp[index] = envelopes[i][1];
            }
        }

        return temp.size();
    }
};