#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            vis[arr[i]]++;
        }
        int dup=0;
        int mis=0;
        for(int i=1;i<n+1;i++){
            if(vis[i]==2) dup=i;
            else if(vis[i]==0) mis=i;
        }
        return {dup,mis};
    }
};