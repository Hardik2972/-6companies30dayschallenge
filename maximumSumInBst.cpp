#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class NodeValue{
    public:
    int minNode, maxNode, maxSize;

    public:
        NodeValue(int minNode, int maxNode, int maxSize){
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};
class Solution {
    int maxSum = 0;
    NodeValue maxSumBSTHelper(TreeNode* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            int sum = left.maxSize + right.maxSize + root->val;
            maxSum = max(maxSum, sum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum > 0 ? maxSum : 0;
    }
};