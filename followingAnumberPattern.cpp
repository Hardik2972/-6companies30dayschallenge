#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int num = 0;
        stack<int> s;
        string ans;
        for(int i=0;i<S.size();i++){
            num++;
            s.push(num);
            if(S[i]=='I'){
                while(!s.empty()){
                   ans+=to_string(s.top());
                   s.pop();
                }
            }
        }
        num++;
        s.push(num);
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        return ans;
    }
};