/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int cnt=0;
   void dfs(TreeNode* root, int maxi){
    if(root==NULL){
        return;
    }
    if(maxi<=root->val){
        cnt++;
        maxi = root->val;
    }
    if(root->left){
     dfs(root->left,maxi);
    }
      if(root->right){
     dfs(root->right,maxi);
    }
   }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        cnt=0;
        dfs(root,root->val);
        return cnt;
    }
};
