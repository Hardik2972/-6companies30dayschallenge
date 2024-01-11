#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first < b.first;
    }
    return false;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            m[words[i]]++;
        }

        vector<pair<string, int>> freqVector(m.begin(), m.end());
        sort(freqVector.begin(), freqVector.end(), cmp);

        vector<string> ans;
        for (int i = 0; i < k && i < freqVector.size(); i++) {
            ans.push_back(freqVector[i].first);
        }

        return ans;
    }
};
