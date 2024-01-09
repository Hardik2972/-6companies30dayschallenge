#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> matrix=img;
        int n = img.size();
        int m = img[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int delCol[]={-1,0,1};
        for(int i=0;i<n;i++){
            int rowCounter = 1;
            if((i-1)>=0) rowCounter++;
            if((i+1)<n) rowCounter++;
            for(int j=0;j<m;j++){
                int colCounter = 0;
                
                int sum = 0;
                for(int k =0;k<3;k++){
                    int col = delCol[k]+j;
                    if(col>=0 && col<m){

                    colCounter++;
                    int prev=0;

                    int next=matrix[i][col];
            
                    if((i-2)>=0){
                        prev=matrix[i-2][col];
                        
                    }
                    if((i+1)<n){
                        next=matrix[i+1][col];
                    
                    }
                    sum+=(next-prev);
                    }
                }
                // cout<<sum<<"  "<<i<<j<<"  "<<rowCounter<<"  "<<colCounter<<endl;
                img[i][j]=(sum/(rowCounter*colCounter));


            }
        }
        return img;
    }
};