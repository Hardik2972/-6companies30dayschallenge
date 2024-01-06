#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int i=0;
        int j=0;
        int count = 0;
        string temp;
        while(j<s.size()){
            
            if(count<=10){
                temp+=s[j];
                // cout<<temp<<endl;
                count++;
            }
            if(count>10){
                temp.erase(temp.begin());
                count--;
                i++;
                
            }
            if(count==10){
                // cout<<temp<<endl;
                m[temp]++;
            } 
            j++;
        }
        vector<string> ans;
        for(auto it:m){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};