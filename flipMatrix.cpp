#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    set<pair<int,int>> s;
    int m;
    int n;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        int row = rand()%m;
        int col = rand()%n;
        while(s.find({row,col})!=s.end()){
            row=rand()%m;
            col=rand()%n;
        }
        s.insert({row,col});
        return {row,col};
    }
    
    void reset() {
        s.clear();
    }
};