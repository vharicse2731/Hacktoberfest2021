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
 
 
 //  https://leetcode.com/problems/leaf-similar-trees/
 
class Solution {
public:
    int k=0;
    void tree1(TreeNode* root,vector<int> &temp){
        if(root==NULL)
            return;
        if(!root->left && !root->right)
            temp.push_back(root->val);
        tree1(root->left,temp);
        tree1(root->right,temp);
    }
    void tree2(TreeNode* root,vector<int> temp,bool *istrue){
        if(root==NULL || !(*istrue))
            return;
        if(!root->left && !root->right)
            if(k >= temp.size() || root->val != temp[k++] )
                *istrue=false;
        tree2(root->left,temp,istrue);
        tree2(root->right,temp,istrue);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2==NULL)
            return false;
        vector<int> temp;
        tree1(root1,temp);
        bool istrue=true;
        tree2(root2,temp,&istrue);
        return istrue;
    }
};

// 2 vector:
class Solution {
public:
    vector <int> v;
    void dfs(TreeNode *p)
    {
        if(!p)
            return;
        if(!p->left&&!p->right)
        {
            v.push_back(p->val);
        }
        dfs(p->left);
        dfs(p->right);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        vector <int> v1=v;
        v.clear();
        dfs(root2);
        vector <int> v2=v;
        return v1==v2;
        
    }
};