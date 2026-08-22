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
   bool ans = true;
   int helper(TreeNode* root){
        if(root==NULL)return 0;
      
      
        int l = helper(root->left);
       
       
       int r = helper(root->right);

       if(abs(l-r)>1){
        ans = false;
        
       }
       return 1+max(l,r);
   } 
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        helper(root);
        return ans;
    }
};
