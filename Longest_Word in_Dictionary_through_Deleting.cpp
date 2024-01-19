#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
bool cmp(string& a,string& b){
    if(a.size()>b.size()) return true;
    else if(a.size()==b.size()) return a<b;
    return false;
}
class Solution {
public:
    bool checker(string& s,string& temp){
        int i=0,j=0;
        while(i<s.size() && j<temp.size()){
            if(s[i]==temp[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==temp.size()) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        string ans = "";
        for(int i=0;i<dictionary.size();i++){
            string temp = dictionary[i];
            if(temp.size()<=s.size() && checker(s,temp)){
                ans = temp;
                break;
            }
        }
        return ans;
    }
};