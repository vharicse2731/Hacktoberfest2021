

// https://practice.geeksforgeeks.org/problems/check-for-bst/1

/*
Using inorder method ----> inorder of bst is in ascending order
*/


bool inorder(Node* root,int *prev){
    if(!root)
        return true;
    bool l = inorder(root->left,prev);
    if(!l)
        return 0;
    if(*prev >=root->data)
        return 0;
    else
        *prev=root->data;
    return inorder(root->right,prev);
    return 1;
}

bool isBST(Node* root) {
    int prev=-1;
    return inorder(root,&prev);
}