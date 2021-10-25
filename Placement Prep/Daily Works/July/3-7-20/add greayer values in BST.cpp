
//  https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1/

int sum;
void make(Node* &root){
    if(!root)
        return;
    make(root->right);
    sum+=root->data;
    root->data=sum;
    make(root->left);
}
Node* modify(Node *root)
{
    sum=0;
    make(root);
    return root;
}