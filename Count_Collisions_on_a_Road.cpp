#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        stack<string> st;
        int collisions = 0;
        map<string,int> m;
        m["RL"]=2;m["RS"]=1;m["SL"]=1;
        for(int i=0;i<directions.size();i++){
            string t;
            t += directions[i];
            st.push(t);
            while(st.size()>=2){
                string temp = st.top();
                st.pop();
                temp=st.top()+temp;
                st.pop();
                
                if(m.find(temp)!=m.end()){
                    collisions+=m[temp];
                    st.push("S");
                }
                else{
                    string t;
                    t +=temp[0];
                    st.push(t);
                    string s;
                    s += temp[1];
                    st.push(s);
                    
                    break;
                }
            }
            
        }

        return collisions;
    }
};