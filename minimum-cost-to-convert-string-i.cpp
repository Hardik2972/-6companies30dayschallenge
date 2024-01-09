#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=changed.size();
        vector<vector<int>> matrix(26,vector<int>(26,1e9));
        for(int i=0;i<n;i++){
            int ori = original[i]-'a';
            int ch = changed[i]-'a';
            matrix[ori][ch]=min(cost[i],matrix[ori][ch]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(i==j) matrix[i][j]=0;
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i=0;i<source.size();i++){
            if(matrix[source[i]-'a'][target[i]-'a']>=1e9) return -1;
            ans+=matrix[source[i]-'a'][target[i]-'a'];
            // cout<<matrix[source[i]-'a'][target[i]-'a']<<endl;
        }
        return ans;

    }
};