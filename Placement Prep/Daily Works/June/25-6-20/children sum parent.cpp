
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1/

int isSumProperty(Node *root)
{
 // Add your code here
 if(root==NULL)
    return 1;
 if(!root->left && !root->right)
    return 1;
 int rc= root->right?root->right->data:0;
 int lc=root->left?root->left->data:0;
 if(root->data==rc+lc && isSumProperty(root->left) && isSumProperty(root->right))
    return 1;
 
 return 0;
}