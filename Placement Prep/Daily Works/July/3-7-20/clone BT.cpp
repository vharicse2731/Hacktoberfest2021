


//  https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1

Node* clone(Node* tree,Node* root){
    if(!tree)
        return NULL;
    Node* temp=new Node(tree->data);
    root=temp;
    root->left=clone(tree->left,root->left);
    root->right=clone(tree->right,root->right);
    return root;
}

Node* cloneTree(Node* tree)
{
    Node* root;
    return clone(tree,root);
}



ALiter:

Node* cloneTree(Node* tree)
{
    if(!tree)
        return NULL;
    Node* root=new Node(tree->data);
    root->left=cloneTree(tree->left);
    root->right=cloneTree(tree->right);
    return root;
}

