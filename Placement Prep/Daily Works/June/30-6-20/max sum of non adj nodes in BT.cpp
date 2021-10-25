

//  https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

USING PAIRS:

#define pr  pair<int,int>
pr helper(Node* root){
    if(root==NULL){
        pr a(0,0);
        return a;
    }
    
    pr leftsum= helper(root->left);
    pr rightsum=helper(root->right);
    
    pr cursum;
    
    cursum.first=root->data+leftsum.second+rightsum.second;
    cursum.second=max(leftsum.first,leftsum.second)+max(rightsum.first,rightsum.second);
    
    return cursum;
}

int getMaxSum(Node *root) 
{
    // Add your code here
    pr ans=helper(root);
    return max(ans.first,ans.second);
}

USING DP:


map<Node*,int> dp;
int helper(Node* root){
    if(root==NULL){
        return 0;
    }
    if(dp.find(root)!=dp.end())
        return dp[root];
        
    int inc=0,exc=0;
    
    inc+=root->data;
    if(root->left)
        inc+=helper(root->left->left)+helper(root->left->right);
    if(root->right)
        inc+=helper(root->right->left)+helper(root->right->right);
    
    exc+=helper(root->left)+helper(root->right);
    
    dp[root]=max(inc,exc);
    return dp[root];
}

int getMaxSum(Node *root) 
{
    dp.clear();
    return helper(root);
}