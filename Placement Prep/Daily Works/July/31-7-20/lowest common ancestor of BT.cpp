
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/

// Lowest common ancestor of binary tree

Node* LCA(Node *root, int n1, int n2)
{
    if(!root)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    Node* l=LCA(root->left,n1,n2);
    Node* r=LCA(root->right,n1,n2);
    if(l && r)
        return root;
    return l?l:r;
}