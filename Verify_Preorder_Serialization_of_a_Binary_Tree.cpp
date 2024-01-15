#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string pre) {
        vector<string> preorder;
        int i = 0;
        while(i<pre.size()){
            string temp1;
            while(i<pre.size() && pre[i]!=','){
                temp1+=pre[i];
                i++;
            }
            if(temp1.size()!=0) preorder.push_back((temp1));
            i++;
        }
        i=0;
        stack<string> q;
        q.push(preorder[i]);
        i++;
        while(!q.empty() && i<preorder.size()){
            if(preorder[i]=="#"){
                if(q.top()=="#"){
                    while(!q.empty() && q.top()=="#"){
                        q.pop();
                        cout<<"pop element "<<endl;
                        if(!q.empty()) {
                            q.pop();
                            cout<<"pop element "<<endl;
                        }
                        else return false;
                    }
                    cout<<"#"<<endl;
                    q.push("#");
                }
                else{
                    cout<<'#'<<endl;
                    q.push("#");
                }
            }
            else{
                cout<<preorder[i]<<endl;
                q.push(preorder[i]);
            }
            i++;
        }
        int n = preorder.size();
        if (q.size() == 1 && q.top() == "#" && i >= n) {
            return true;
        }
        return false;
    }
};