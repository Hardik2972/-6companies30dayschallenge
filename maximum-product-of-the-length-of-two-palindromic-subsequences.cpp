#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        int i  = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int maxProduct(string s) {
        unordered_map<int,int> m;
        int n = s.size();
        for(int i=0;i<(1<<n);i++){
            string temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) temp+=s[j];
            }
            if(isPalindrome(temp)) m[i]=temp.size();
        }
        int maxi = 0;
        for(auto& it:m){
            cout<<"hell"<<endl;
            for(auto it1:m){
                
                if((it.first&it1.first)==0){
                    maxi=max(maxi,it.second*it1.second);
                }
            }
        }
        return maxi;
    }
};