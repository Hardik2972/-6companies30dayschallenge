#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<set>
using namespace std;

class ThroneInheritance {
public:
    unordered_map<string,vector<string>> m;
    unordered_set<string> dead;
    string Kname;
    ThroneInheritance(string kingName) {
        Kname = kingName;
    }
    
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    void dfs(auto& m,auto& dead,auto& ans,string head){
        if(dead.find(head)==dead.end()){
            ans.push_back(head);
        }
        int size = m[head].size();
        for(int i=0;i<size;i++){
            dfs(m,dead,ans,m[head][i]);
        }

    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(m,dead,ans,Kname);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */