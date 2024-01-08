#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                    matrix[i][j]=min(matrix[i][k]+matrix[k][j],matrix[i][j]);
                    }                
                }
            }
        }
        int ans = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int tempCount = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=threshold) {
                    tempCount++;
                    
                }
            }
       
            if(mini>=tempCount){
                ans = i;
                mini=tempCount;
            } 
        }
        return ans;
    }
};