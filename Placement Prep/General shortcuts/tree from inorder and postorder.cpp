

// construct tree from inorder and postorder

//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

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
    TreeNode* build(vector<int>& in, vector<int>& po,int &ind,int st,int en) {
        if(st>en) return NULL;
        int temp=st;
        TreeNode* root=new TreeNode(po[ind]);
        while(in[temp]!=root->val)
            temp++;
        ind--;
        root->right=build(in,po,ind,temp+1,en);
        root->left=build(in,po,ind,st,temp-1);
        
        return root;
    }   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=postorder.size()-1;
        return build(inorder,postorder,i,0,inorder.size()-1);
    }
};