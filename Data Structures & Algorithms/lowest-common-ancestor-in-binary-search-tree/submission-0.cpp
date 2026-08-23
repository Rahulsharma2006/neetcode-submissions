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
TreeNode* ans = NULL;
  void lcs(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL)return ;
    if(root->val==p->val || root->val == q->val){
        ans = root;
        return ;
    }
    if(root->val>q->val){
        lcs(root->left,p,q);
    }
    else if (root->val<p->val){
        lcs(root->right,p,q);
    }else{
        ans = root;
        return;
    }
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val){
            lcs(root,p,q);
        }else{
            lcs(root,q,p);
        }
        return ans;
    }
};
