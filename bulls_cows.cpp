#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull =0;
        int cow = 0;
        unordered_map<char,int> m;
        unordered_map<int,int> ma;
        for(int i=0;i<secret.size();i++){
            if(guess[i]==secret[i]) {
               bull++;
               ma[i]++;
            }
            else{
                m[secret[i]]++;
            }
            
        }
        for(int i=0;i<guess.size();i++){
            if(m.find(guess[i])!=m.end() && m[guess[i]]>=1 && ma.find(i)==ma.end()){
                 cow++;
                 m[guess[i]]--;
            }
        }
        string ans = to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};