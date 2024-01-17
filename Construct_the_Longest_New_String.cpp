#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x,y);
        if (x == y)
            return (4 * x + z * 2);
        else 
            return (2 * mn + (mn + 1) * 2 + z * 2);
    }
};