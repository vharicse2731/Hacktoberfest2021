
// https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1/

map<int,int>dp;

int helper(Node* root){
    if(root==NULL)
        return 0;
    if(dp.find(root->data)!=dp.end())
        return dp[root->data];
    int inc=0,exc=0;
    if(root->left){
        inc+=helper(root->left->left)+helper(root->left->right);
    }
    if(root->right){
        inc+=helper(root->right->left)+helper(root->right->right);
    }
    inc++;
    exc+=helper(root->left)+helper(root->right);
    dp[root->data]=max(inc,exc);
    return dp[root->data];
}

int LISS(struct Node *root)
{
    dp.clear();
    return helper(root);
}


Other:

bool fun(struct Node *root,int &temp)
{
if(root==NULL)
return false;
bool c =fun(root->left,temp);
bool d= fun(root->right,temp);
if(c==false&&d==false)
{
temp++;
return true;
}
return false;
}
int LISS(struct Node *root)
{
int temp=0;
bool t=fun(root,temp);
return temp;
}