#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    int friendCounter(int j,vector<int>& ages){
        int lowerCondition = 0.5*ages[j]+7;
        int lowestIndex = lower_bound(ages.begin(),ages.end(),lowerCondition+1) - ages.begin();
        if(lowestIndex>=j) return 0;
        return j-lowestIndex;
    }
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(),ages.end());
        unordered_map<int,int> m;
        unordered_map<int,int> ma;
        for(int i=0;i<ages.size();i++){
            m[ages[i]]=i;
            ma[ages[i]]++;
        }
        for(auto it:m){
            ans+=ma[it.first]*friendCounter(it.second,ages);
        }
        return ans;
    }
};