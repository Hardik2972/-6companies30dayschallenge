#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(isWater.size(),vector<int>(isWater[0].size(),0));
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1) {
                   q.push({i,j});
                   isWater[i][j]=0;
                   vis[i][j]=1;
                }
            }
        }
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,-1,0,1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
        
            for(int i=0;i<4;i++){
                int row = r + delRow[i];
                int col = c + delCol[i];
                if(row>=0 && col>=0 && row<isWater.size() && col<isWater[0].size() && vis[row][col]==0){
                    q.push({row,col});
                    isWater[row][col]=isWater[r][c]+1;
                    vis[row][col]=1;
                }
            }
        }
        return isWater;
        
    }
};