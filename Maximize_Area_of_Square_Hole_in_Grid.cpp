#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hBarMaxi = 2;
        int vBarMaxi = 2;
        int count = 2;
      for(int i = 1; i < hBars.size(); ++i) {
          count = (hBars[i-1]+1 == hBars[i])? count + 1: 2;
          hBarMaxi = max(hBarMaxi, count);
      }
       count = 2;
      for(int i = 1; i < vBars.size(); ++i) {
          count = (vBars[i-1]+1 == vBars[i])? count + 1: 2;
          vBarMaxi = max(vBarMaxi, count);
      }
        
        
        int ans = min(vBarMaxi,hBarMaxi);
        return ans*ans;
    }
};