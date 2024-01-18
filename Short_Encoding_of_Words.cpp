#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]=i;
        }
        for(auto it:m){
            string temp = it.first;
            int n = temp.size();
            string temp1;
            for(int i=n-1;i>=0;i--){
                temp1=temp[i]+temp1;
                // cout<<temp1<<endl;
                if(m.find(temp1)!=m.end() && m[temp1]!=m[it.first]){
                    m.erase(temp1);
                    // cout<<"i am found"<<endl;
                }
            }
        }
        int ans=0;
        for(auto it:m){
            ans+=it.first.size()+1;
        }
        return ans;
    }
};