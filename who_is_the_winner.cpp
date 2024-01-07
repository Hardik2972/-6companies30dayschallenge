#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int count = 1;
            while(count<=k){
                // cout<<q.front()<<endl;
                if(count==k){
                    // cout<<"this is deleted "<<q.front()<<endl;
                    q.pop();
                }
                else{
                   int front = q.front();
                   q.pop();
                   q.push(front);
                }
                count++;
            }

        }
        return q.front();
    }
};