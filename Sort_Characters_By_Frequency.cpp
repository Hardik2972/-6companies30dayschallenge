#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

bool cmp(pair<char,int>& a,pair<char,int>& b){
    return a.second>b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> sortedVec(m.begin(),m.end());
        sort(sortedVec.begin(),sortedVec.end(),cmp);
        int i=0;
        for(auto it:sortedVec){
            for(int j=0;j<it.second;j++){
                s[i++]=it.first;
            }
        }
        return s;

    }
};