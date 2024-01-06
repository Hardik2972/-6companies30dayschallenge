#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    double distanceCalculator(vector<int> temp1,vector<int> temp2){
        double x = (temp1[0]-temp2[0])*(temp1[0]-temp2[0]);
        double y = (temp1[1]-temp2[1])*(temp1[1]-temp2[1]);
        return sqrt(x + y);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        vector<int> circle={xCenter,yCenter};
        int i = max(x1,min(xCenter,x2));
        int j = max(y1,min(yCenter,y2));
        double dist = distanceCalculator(circle,{i,j});
        if(dist<=radius) return true;
        return false;
    }
};