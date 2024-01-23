#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    bool search(int element,vector<int>& b,int k){
        int start = 0;
        int end = b.size()-1;
        int ans = -1;
        if(end==-1) return false;
        while(start<=end){
            // cout<<"dilsjf";
            int mid = start+(end-start)/2;
            if(b[mid]>=element){
                ans=mid;
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        if(ans==-1 && (end)>=0){
            // cout<<((element-b[b.size()-1])<=k);
            return (element-b[b.size()-1])<=k;
        }
        else if(ans==0){
            return (b[ans]-element)<=k;
        }
        else{
            bool a = ((element-b[ans-1])<=k || (b[ans]-element)<=k) ;
            return a;
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> b_counter;
        vector<int> a_counter;
        int a_len = a.size();
        int b_len = b.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==a[0] && s.substr(i,a_len)==a) a_counter.push_back(i);
            if(s[i]==b[0] && s.substr(i,b_len)==b) b_counter.push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<a_counter.size();i++){
            // cout<<i<<"hi aihsdf "<<endl;
            if(search(a_counter[i],b_counter,k)){
                ans.push_back(a_counter[i]);
            }
        }
        
        return ans;
    }
};