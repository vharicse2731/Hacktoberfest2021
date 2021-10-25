
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->right),height(root->left))+1;
    }
    void level(TreeNode* root,vector<vector<int>> &ans,int l){
        if(!root)
            return;
        ans[l].push_back(root->val);
        level(root->left,ans,l-1);
        level(root->right,ans,l-1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h=height(root);
        vector<vector<int>>ans(h,vector<int>{});
        level(root,ans,h-1);
        return ans;
    }
};