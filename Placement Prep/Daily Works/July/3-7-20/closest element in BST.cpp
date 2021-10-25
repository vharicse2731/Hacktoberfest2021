

//  https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/

void bst(Node *root,int K,int *mini){
    if(!root)
        return;
    *mini=min(*mini,abs(root->data-K));
    if(root->data < K)
        bst(root->right,K,mini);
    else
        bst(root->left,K,mini);
}

int minDiff(Node *root, int K)
{
    int mini=INT_MAX;
    bst(root,K,&mini);
    return mini;
}