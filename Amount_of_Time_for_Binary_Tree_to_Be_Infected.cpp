#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
           
            q.pop();
            if(top->left){
                m[top->val].push_back(top->left->val);
                m[top->left->val].push_back(top->val);
                q.push(top->left);
            }
            if(top->right){
                m[top->val].push_back(top->right->val);
                m[top->right->val].push_back(top->val);
                q.push(top->right);
            }
        }
        queue<int> q2;
        q2.push(start);
        int ans =-1;
        unordered_map<int,int> visited;
        visited[start] = 1;
        while(!q2.empty()){
            
            ans++;
            int size = q2.size();
            for(int j=0;j<size;j++){
            int top = q2.front();
            q2.pop();
            for(int i=0;i<m[top].size();i++){
                if(visited.find(m[top][i])==visited.end()){
                    visited[m[top][i]]=1;
                    q2.push(m[top][i]);
                }
            }
            }
        }

        return ans;
    }
};