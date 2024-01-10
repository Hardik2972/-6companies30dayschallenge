#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int n;
    vector <int> ps;
    int area(vector<int> &r) {
        return ((r[2]-r[0]+1))*((r[3]-r[1]+1));
    }
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        ps.resize(n);
        ps[0] = area(rects[0]);
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i-1] + area(rects[i]); 
        }
    }
    
    vector<int> pick() {
        int k = rand()%ps[n-1]; 
        int idx = lower_bound(ps.begin(), ps.end(), k+1) - ps.begin();
        k -= (idx > 0 ? ps[idx-1] : 0); 
        int side = rects[idx][2]-rects[idx][0]+1; 
        return {rects[idx][0] + k%side, rects[idx][1] + k/side}; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */