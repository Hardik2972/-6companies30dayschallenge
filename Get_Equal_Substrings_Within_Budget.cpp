#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n =s.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(abs(s[i]-t[i]));
        }
        int i=0;
        int j=0;
        int ans = 0;
        int count = 0;
        while(j<n){
           count+=temp[j];
           while(count>k){
               count-=temp[i];
               i++;
           }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};