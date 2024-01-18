#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        queue<pair<int,int>> q;
        q.push({rCenter,cCenter});
        vector<vector<int>> vis(rows,vector<int>(cols,-1));
        vis[rCenter][cCenter] = 1;
        vector<vector<int>> ans;
        ans.push_back({rCenter,cCenter});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int topRow = q.front().first;
            int topCol = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int tempRow = delRow[i] + topRow;
                int tempCol = delCol[i] + topCol;
                if(tempRow>=0 && tempCol>=0 && tempRow<rows && tempCol<cols && vis[tempRow][tempCol]==-1){
                    q.push({tempRow,tempCol});
                    ans.push_back({tempRow,tempCol});
                    vis[tempRow][tempCol] = 1;
                }
            }
        }
        return ans;
    }
};